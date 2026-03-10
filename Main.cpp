#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const char* ssid = "LEAD_WiFi";
const char* password = "";

WebServer server(80);
DNSServer dnsServer;

const byte DNS_PORT = 53;

int visitorCount = 0;

const int redLED = 2;
const int blueLED =4;

unsigned long previousMillis = 0;
bool redState = false;

String portalPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">

<title>Secure Gateway</title>

<style>

body{
background:black;
color:#00ff9c;
font-family:monospace;
margin:0;
padding:20px;
}

#terminal{
font-size:16px;
white-space:pre-line;
}

.cursor{
display:inline-block;
width:10px;
background:#00ff9c;
margin-left:3px;
animation:blink 1s infinite;
}

@keyframes blink{
0%{opacity:1;}
50%{opacity:0;}
100%{opacity:1;}
}

.login{
display:none;
margin-top:30px;
background:#111827;
padding:25px;
border-radius:8px;
color:white;
text-align:center;
font-family:Arial;
}

input{
width:90%;
padding:10px;
margin:8px;
border-radius:5px;
border:none;
background:#020617;
color:white;
}

button{
width:95%;
padding:12px;
background:#00ff9c;
border:none;
border-radius:6px;
color:black;
font-weight:bold;
cursor:pointer;
}

.error{
color:#ff4d4d;
font-size:12px;
}

.progress{
height:6px;
background:#022c22;
margin-top:15px;
}

.bar{
height:6px;
width:0%;
background:#00ff9c;
}

.footer{
font-size:12px;
margin-top:10px;
color:#9ca3af;
}

</style>

<script>

var lines=[
"> Booting Network Gateway...",
"> Loading Security Modules...",
"> Scanning Connected Devices...",
"> Checking Firewall Integrity...",
"> Initializing Captive Portal..."
];

var line=0;

function typeLine(){

if(line<lines.length){

var text=lines[line];
var i=0;

var interval=setInterval(function(){

document.getElementById("terminal").innerHTML+=text[i];

i++;

if(i>=text.length){
clearInterval(interval);
document.getElementById("terminal").innerHTML+="\n";
line++;
setTimeout(typeLine,700);
}

},40);

}else{

startProgress();

}

}

function startProgress(){

var bar=document.getElementById("bar");

var width=0;

var progress=setInterval(function(){

width++;

bar.style.width=width+"%";

if(width>=100){

clearInterval(progress);

document.getElementById("login").style.display="block";

}

},25);

}

function validateForm(){

var email=document.getElementById("email").value;

var regex=/^[^ ]+@[^ ]+\.[a-z]{2,3}$/;

if(!regex.test(email)){
document.getElementById("error").innerHTML="Invalid email format";
return false;
}

return true;

}

window.onload=typeLine;

</script>

</head>

<body>

<div id="terminal"></div>

<div class="progress">
<div id="bar" class="bar"></div>
</div>

<div id="login" class="login">

<h2>Secure Network Access</h2>

<form action="/submit" onsubmit="return validateForm()">

<input name="name" placeholder="User Name" required>

<input id="email" name="email" placeholder="User Email" required>

<div id="error" class="error"></div>

<button type="submit">Authorize Access</button>

</form>

<div class="footer">
Developed by Vishnu K
</div>

</div>

</body>
</html>
)rawliteral";

void handleRoot(){
server.send(200,"text/html",portalPage);
}

void handleSubmit(){

visitorCount++;

String name=server.arg("name");
String email=server.arg("email");

Serial.println("-------- New User --------");
Serial.print("Visitor #: ");
Serial.println(visitorCount);
Serial.print("Name: ");
Serial.println(name);
Serial.print("Email: ");
Serial.println(email);
Serial.println("--------------------------");

// Blue LED blink
for(int i=0;i<6;i++){
digitalWrite(blueLED,HIGH);
delay(80);
digitalWrite(blueLED,LOW);
delay(80);
}

String response="<html><body style='background:black;color:#00ff9c;font-family:monospace;text-align:center;padding-top:100px;'>";

response+="<h2>ACCESS LOGGED</h2>";

response+="<p>User: "+name+"</p>";
response+="<p>Email: "+email+"</p>";

response+="<p style='color:#ff4d4d'>Cybersecurity Awareness Demo</p>";

response+="<p>Visitors Logged: ";
response+=visitorCount;
response+="</p>";

response+="<button onclick='showDev()' style='padding:12px 20px;background:#00ff9c;border:none;border-radius:6px;color:black;'>Developer</button>";

response+="<script>";

response+="function showDev(){";

response+="document.body.innerHTML=`";

response+="<div style='display:flex;justify-content:center;align-items:center;height:100vh;color:#00ff9c;font-family:monospace;text-align:center;'>";

response+="<div>";

response+="<h2>NETWORK SWITCH REQUIRED</h2>";

response+="<p>Enable Mobile Data or Internet Connection</p>";

response+="<button onclick=\\\"window.location.href='https://vishnucax.github.io/future-predictor'\\\" style='padding:12px 20px;background:#00ff9c;border:none;border-radius:6px;color:black;'>Open Developer Site</button>";

response+="<p style='margin-top:20px;font-size:12px;color:#9ca3af;'>Developed by Vishnu K</p>";

response+="</div></div>`;";

response+="}";

response+="</script>";

response+="</body></html>";

server.send(200,"text/html",response);

}

void setup(){

Serial.begin(115200);

pinMode(redLED,OUTPUT);
pinMode(blueLED,OUTPUT);

WiFi.softAP(ssid,password);

Serial.println("Hotspot Started");
Serial.println(WiFi.softAPIP());

dnsServer.start(DNS_PORT,"*",WiFi.softAPIP());

server.on("/",handleRoot);
server.on("/generate_204",handleRoot);
server.on("/hotspot-detect.html",handleRoot);
server.on("/ncsi.txt",handleRoot);
server.on("/submit",handleSubmit);
server.onNotFound(handleRoot);

server.begin();

}

void loop(){

dnsServer.processNextRequest();
server.handleClient();

unsigned long currentMillis=millis();

if(currentMillis-previousMillis>=700){

previousMillis=currentMillis;

redState=!redState;

digitalWrite(redLED,redState);

}

}
