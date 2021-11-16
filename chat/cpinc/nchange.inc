#!/usr/bin/perl

print "Content-type: text/html\n\n";

dbmopen(%O,"$root/ops/ops/$DATA{'ops'}",0777);

if($O{'level'} < $staff_rank){

$error = "Control Panel, please login!";

require "$root/cpinc/login.inc";

dbmclose(%O);
exit;

}
dbmclose(%O);

if(!$DATA{'b'}){

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title Chat!</title>
</head>
<body>
<center><font size=+3 color=#FF0000><i>Check Ops Application / Nickname Change</i></font></center>
<form method="POST" action="cp.cgi">
  <div align="center"><center><p>Input Application Code:<br>
  <input type="text" name="b" size="20" maxlength="40"></p>
  </center></p>
  </center></div><div align="center"><center><p><input type="submit" value="Check"></p>
  </center></div>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="nchange" name="a">
</form>
</body>
</html>


(END HTML FOOTER)

exit;

}


if($DATA{'b'} && !$DATA{'c'}){


if(!-e "$root/appchange/$DATA{'b'}"){


print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title Chat!</title>
</head>
<body>
<center><font size=+3 color=#FF0000><i>Check Ops Application / Nickname Change</i></font>\n<p>Error, application with code <b>$DATA{'b'}</b> not found.<p></center>
<form method="POST" action="cp.cgi">
  <div align="center"><center><p>Input Application Code:<br>
  <input type="text" name="b" size="20" maxlength="40"></p>
  </center></p>
  </center></div><div align="center"><center><p><input type="submit" value="Check"></p>
  </center></div>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="nchange" name="a">
</form>
</body>
</html>


(END HTML FOOTER)

exit;
}





dbmopen(%O,"$root/appchange/$DATA{'b'}",0777);


print <<"(END HTML FOOTER)";


<head><title>$title Chat</title>
</head>

<body><center><b>Application with code <b>$DATA{'b'}</b>.</b></center><p><p>
<center><table width=500><tr><td>

<FORM METHOD="POST" NAME="msg" ACTION="cp.cgi">

<b>Nickname : <font color="red">$O{'old_nick'} </font></b><p>
<b>New Nickname : <font color="red">$O{'new_nick'} </font></b><p>


<INPUT type="hidden" name="c" value="yes"><p>
<INPUT type="hidden" name="b" value="$DATA{'b'}"><p>

</table>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="nchange" name="a">

<br><INPUT TYPE=SUBMIT VALUE="  ADD/ CHANGE NICK  "> || <b><a href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=nchange"> ABORT</a><b><br></body>

(END HTML FOOTER)

dbmclose(%O);

exit;

}

#

dbmopen(%O,"$root/appchange/$DATA{'b'}",0777);

rename("$root/ops/ops/$O{'old_nick'}","$root/ops/ops/$O{'new_nick'}");

rename("$root/opspreferences/$O{'old_nick'}","$root/opspreferences/$O{'new_nick'}");

dbmopen(%ME,"$root/ops/ops/$DATA{'ops'}",0777);

$ME{'total_money'} = $ME{'total_money'} + 15;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$O{'old_nick'} -> $O{'new_nick'}\|\| \$15 \|\| NICKNAME CHANGE";

$ME{'total_renewals'} = $ME{'total_nchange'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 15;

dbmclose(%M);

$old=$O{'old_nick'};
$new=$O{'new_nick'};


dbmclose(%O);

unlink ("$root/appchange/$DATA{'b'}");


dbmopen(%O,"$root/ops/ops/$new",0777);


    open(MAIL,"|$sendmail -t");
    print MAIL "To: $US{'email'}\n";
    print MAIL "From: webmaster\@ulyaoth.com (Ulyaoth Chat Admin)\n";
    print MAIL "Subject: Ulyaoth Chat Membership!\n";
    print MAIL "Your Ops nickname has been changed, please do NOT print this email or forward to someone else.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Nick: $old\n";
    print MAIL "New Nick: $new\n";
    print MAIL "Email: $US{'email'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Ulyaoth Chat! Admin\n https:\/\/chat.ulyaoth.com\n";
    close(MAIL);




print <<"(END HTML FOOTER)";


<head><title>$title Chat</title>
</head>

<body><center><b>Account with nickname <b><font color=red>$old</font></b> successfuly changed to <b>$new</b>.</center><p><p>



</body>
</html>

(END HTML FOOTER)

return true;
