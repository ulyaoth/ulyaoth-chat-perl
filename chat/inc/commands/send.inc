#!/usr/bin/perl


@send = split(/\s+/,$DATA{'msg'});


unless(@send[1]){

$errors = " Syntax: /send [nick].";

return $errors;

exit;

}


if(!-e "$root/online/users/@send[1]"){

$errors = " Error, user <b>@send[1]</b> not found.";

return $errors;

exit;

}




print "Content-type: text/html\n\n";

print <<"(END HTML FOOTER)";

<HEAD><title>$title</TITLE>
<BODY $bgcolor $text onLoad="window.status='$version';">

<form method=post enctype="multipart/form-data" action="/cgi-bin/upload.cgi">

<center><table width=500><tr><td><b><font size=-1>
<b>$title Chat File Transfer</b><hr><br><br><br><center><table>
<tr><td align=right><b>Upload File</b></td><td align=left><b><input type="file" name="FILE1" value=""></b></td></tr>
<tr><td align=right><b>FileSize</b></td><td align=left><b>1 MB Limit</b></td></tr>
<input type="hidden" name="n" value="$DATA{'n'}">
<input type="hidden" name="id" value="$DATA{'id'}">
<INPUT type="hidden" name="room" value="$DATA{'room'}">
<INPUT type="hidden" NAME="j" VALUE="7">
<input type="hidden" name="send_to" value="@send[1]">
<tr><td> </td>
<td align=left><b><input type=submit value="SUBMIT / SEND FILE"></form>

</table>
</center></td></tr>
</table><p><b><a href="/cgi-bin/c/bin.cgi?n=$DATA{'n'}&id=$DATA{'id'}&room=$DATA{'room'}">ABORT FILE TRANSFER</a></b></center>

</BODY>


(END HTML FOOTER)

exit;


