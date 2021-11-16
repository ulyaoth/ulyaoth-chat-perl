#!/usr/bin/perl

print "Content-type: text/html\n\n";


open(DEL,"$root/mail/$DATA{'ops'}.txt");

 flock(DEL,1);

@dell = <DEL>;

close(DEL);

open(DEL2,">$root/mail/$DATA{'ops'}.txt");

flock(DEL2,2);

foreach $mail(@dell){

if($mail !~ /$DATA{'b'}/){

   print DEL2 $mail;



  }


}

close(DEL2);


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


open(DL,"$root/mail/$DATA{'ops'}.txt");

flock(DL,1);

@dl = <DL>;

close(DL);

$x = 0;

foreach $thing(@dl){

$x++;

}

dbmopen(%MAIL,"$root/opspreferences/$DATA{'ops'}",0777);


if($x == 0){

$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>0</b>. New: <b>0</b>. Please use /mail [nick] to send.";

}else{


$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>$x</b>. New: <b>0</b>. Please use /mail to read cmail and set your options, /mail [nick] to send.";

}


dbmclose(%MAIL);


return true;



