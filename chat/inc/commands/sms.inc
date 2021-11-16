#!/usr/bin/perl

if ($command eq '/sms' && $level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

print "Content-type: text/html\n\n";

print "<head><title>$title Chat</title>\n</head>\n\n<body $bgcolor $text><center><b>$title Simple Message Service (SMS) service.</b></center><p><p>\n";

print <<"(END HTML FOOTER)";
<center>
<table border="0">
<hr>
<center><b>This service will allow you to send an SMS.</b></center>
<hr>
<form action="$location" name="msg" method="POST">

<td>Phone # :</td>
            <td><input type="text" size="15" name="sms" value=""></td>
        </tr>

 <tr>
            <td valign="top">Message :</td>
            <td><textarea name="sms_message" rows="8" cols="60"></textarea><p></td>
        </tr>

<p>
<table border="0" cellpadding="0" cellspacing="0" width="31%" cols="2">
        <tr>
            <td align="center"><input type="submit" value="SEND SMS"></td>
            <td align="center"><input type="reset"  value=" RESET "></td>
        </tr>
    </table>
(END HTML FOOTER)
print "</table>\n</center>\n";

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$DATA{'id'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"msg\" VALUE=\"/sms2\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$DATA{'room'}\">\n</form>\n";


print "</body>\n";

exit;


