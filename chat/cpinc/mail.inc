#!/usr/bin/perl

print "Content-type: text/html\n\n";

open(CM,"$root/mail/$DATA{'ops'}.txt");

@cc = <CM>;

close(CM);

$h = 0;

foreach$j(@cc){

$h++;

}

if($h == 0){


print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<center>You have NO chat mail, please click <a href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=sendmail">HERE</a> to send!</center>

</body>
</html>

(END HTML FOOTER)

return true;

exit;

}



print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#ffffff" text="#000000">
<p><p><b>||<a href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=cmail">Inbox</a> || <a href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=sendmail">Compose</a> ||</b><p>

(END HTML FOOTER)

open(CHECKCMAIL,"$root/mail/$DATA{'ops'}.txt");

@checkcmail = <CHECKCMAIL>;

foreach $line(@checkcmail){

($c1,$c2,$c3)=split(/\|\"\'\|/,$line);


$c3 =~ s/^\s+//ig;

$c3 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

print "<b>OPTIONS: <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=del&b=$c1\">DEL</a> | <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=addwait&b=$c2\">Add WAIT</a> | <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=sendmail&b=$c2\">REPLAY</a></b><br>\n $c3\n\n<hr>";

}


print "</body>\n</html>";

return true;
