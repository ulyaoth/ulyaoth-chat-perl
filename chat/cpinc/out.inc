#!/usr/bin/perl

print "Content-type: text/html\n\n";


unlink ("$root/cp/$DATA{'ops'}");

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<center>Thank you for using our Control Panel!</center>

</body>
</html>


(END HTML FOOTER)

return true;
