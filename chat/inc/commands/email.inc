#!/usr/bin/perl


if ($level < $admin_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}


@email = split(/\s+/, $DATA{'msg'});

if(@email[1] eq "deopped"){

&email('deopped');

}elsif(@email[1] eq "suspended"){

&email('suspended');

}elsif(@email[1] eq "comm"){

&email('comm');

}elsif(@email[1] eq "staff"){

&email('staff');

}elsif(@email[1] >= 1 && @email[1] < 210){

&email(@email[1]);

}else{

$errors = " Error, syntax: /email [1\-$admin_rank], /email deopped, /email suspended, /email staff, /email comm.";

return $errors;

exit;

}



sub email{

my($to) = @_;

print "Content-type: text/html\n\n";

print "<head><title>$title Chat</title>\n</head>\n\n<body $bgcolor $text><center><b>$title email service.</b></center><p><p>\n";

print <<"(END HTML FOOTER)";
<center>
<table border="0">
<hr>
<center><b>Input email. Sending to ($to)</b></center>
<hr>
<form action="$location" name="msg" method="POST">

<td>E-mail from:</td>
            <td><input type="text" size="15" name="from" value=""> default:<b> $webmaster (webmaster)</b></td>
        </tr>

 <tr>
            <td valign="top">Message :</td>
            <td><textarea name="email_message" rows="8" cols="60"></textarea><p></td>
        </tr>

<p>
<table border="0" cellpadding="0" cellspacing="0" width="31%" cols="2">
        <tr>
            <td align="center"><input type="submit" value="SEND EMAIL"></td>
            <td align="center"><input type="reset"  value="   RESET  "></td>
        </tr>
    </table>
(END HTML FOOTER)
print "</table>\n</center>\n";

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$DATA{'id'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"msg\" VALUE=\"/email2 $to\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$DATA{'room'}\">\n</form>\n";


print "</body>\n";

exit;

}























