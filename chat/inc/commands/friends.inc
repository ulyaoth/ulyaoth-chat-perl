#!/usr/bin/perl

@fr = split(/\s+/,$DATA{'msg'});

unless(@fr[1] eq '-'){

dbmopen(%F,"$root/online/users/$DATA{'n'}.db",0777);

if(!$F{'friends_for'}){

dbmclose(%F);

print "Content-type: text/html\n\n";

print "<head><title>$title Chat</title>\n</head>\n\n<body $bgcolor $text><center><b>$title / Make friends.</b></center><p><p>\n";

print <<"(END HTML FOOTER)";
<center>
<table width=500><tr><td><b><font size=-1><hr>
<center><b>$title / simple way of getting to know other people with the same interest.<br><hr>

We are giving you 2 choices which we will match up with other chatters to

find those who might be compatible for your interest.<p></b></center><hr>
<form action="$location" name="msg" method="POST">

<input type=radio name=for value="1"> You're <b>FEMALE</b>, looking for male chatters<br>
<input type=radio name=for value="2"> You're <b>FEMALE</b>, looking for female chatters<br>
<input type=radio name=for value="3"> You're <b>FEMALE</b>, any chatters<br>
<input type=radio name=for value="4"> You're <b>MALE</b>, looking for female chatters<br>
<input type=radio name=for value="5"> You're <b>MALE</b>, looking for male chatters<br>
<input type=radio name=for value="6"> You're <b>MALE</b>, any chatters<hr>


<input type=radio name=mature value="0"> You're a <b>YOUNG</b> chatter, want young chat<br>
<input type=radio name=mature value="1"> You're a <b>MATURE</b> chatter, want mature chat<hr>

</font>

(END HTML FOOTER)

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$DATA{'id'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"msg\" VALUE=\"/friends2\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$DATA{'room'}\">\n\n";

print "<INPUT TYPE=\"submit\" VALUE=\" MAKE FRIENDS NOW \"> || <b><a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/friends+-\">ABORT / DISABLE</a></b></form>\n";

print "</table>\n</center>\n";

print "</body>\n";

exit;

}else{

$me = $F{'friends_me'};

$mature = $F{'friends_mature'};

$looking_for = $F{'friends_for'}; 

dbmclose(%F);

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

opendir(DIR,"$root/online/users/");

flock(DIR,2);

@array = readdir(DIR);

closedir(DIR);

$count = 0;

foreach $e(@array){


if($e ne '.' && $e ne '..'){


$e =~ s/.db//ig;

dbmopen(%E,"$root/online/users/$e",0777);


if($me eq $E{'friends_for'} && $looking_for eq $E{'friends_me'} && $mature eq $E{'friends_mature'}){

$count++;

print "*** Chatter <b><A HREF=\"javascript:m(\'$e\')\">$e</a></b> ($E{'ip'}) is looking for new friends.<br>\n";




			}

dbmclose(%E);

	}

}

print "TOTAL MATCHES: <b>$count</b><br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;

}

}


dbmopen(%F,"$root/online/users/$DATA{'n'}.db",0777);

undef $F{'friends_mature'};

undef $F{'friends_for'};

undef $F{'friends_me'};

dbmclose(%F);

$errors = " Make friends mode disabled. Use /friends to enable again.";

return $errors;

exit;