#!/usr/bin/perl



if ($command eq '/account' && $level < 1){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

dbmopen(%D,"$root/ops/ops/$realnick.db",0777);


open(M,"$root/time/$realnick.dat");

flock(M,1);

$n = <M>;

$i = $n + $online_time;

$m_time = &hms($i);

close(M);


sub hms {
    my $seconds = shift;
    my $minutes = int $seconds / 60;
    my $hours = int $minutes / 60;
    $minutes = $minutes % 60;
    $seconds = $seconds % 60;
    return sprintf "%02d:%02d:%02d", $hours,$minutes,$seconds;
}




###############

print "Content-type: text/html\n\n";

print "<head><title>$title Chat</title>\n</head>\n\n<body $bgcolor $text><center><b>Welcome $realnick ($DATA{'n'}), this form will allow you to view your account information and/or change your password.</b></center><p><p>\n";

print <<"(END HTML FOOTER)";

<center>
<form action="$location" name="msg" method="POST">

<TABLE border="1">
							<TR><TD ALIGN=right>* Nickname&nbsp;</TD><TD ALIGN=left><font color="red"><b>&nbsp;$realnick</b></font></TD></TR>
<TR><TD ALIGN=right>* Change password&nbsp;</TD><TD ALIGN=left>&nbsp;<input type=radio name="chpass" value="yes"> YES&nbsp;<input type=radio name="chpass" checked value=""> NO</TR>
  

	<TR><TD ALIGN=right>* Input old password&nbsp;</TD><TD ALIGN=left>&nbsp;<INPUT SIZE=14 MAXLENGTH=14 TYPE="password" NAME="passw" VALUE=""></TR>
          		<TR><TD ALIGN=right>* Input new password&nbsp;</TD><TD ALIGN=left>&nbsp;<INPUT SIZE=14 MAXLENGTH=14 TYPE="password" NAME="password1" VALUE=""></TR>
            <TR><TD ALIGN=right>* Retype Password&nbsp;</TD><TD ALIGN=left>&nbsp;<INPUT SIZE=14 MAXLENGTH=14 TYPE="password" NAME="password2" VALUE=""></TR>
<TR><TD ALIGN=right>* Level&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'level'}</font></b></TR>

			<TR><TD ALIGN=right>First Name&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'name'}</font></b></TR>
			<TR><TD ALIGN=right>Surname&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'surname'}</font></b></TR>
			<TR><TD ALIGN=right>Street Address&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'street'}</font></b></TD></TR>
			<TR><TD ALIGN=right>Zip code&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'zipcode'}</font></b> </TD></TR>
			<TR><TD ALIGN=right>Country&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'country'}</font></b></TD></TR>
			<TR><TD ALIGN=right>Phone Number&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'phone'}</font></b></TD></TR>
		
<TR><TD ALIGN=right>* Account Started&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'ops_began'}</font></b></TD></TR>
                  <TR><TD ALIGN=right>* Account Ending&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$D{'ops_end'}</font></b></TD></TR>
                  <TR><TD ALIGN=right>* Online Time ($amonth)&nbsp;</TD><TD ALIGN=left><font color="red">&nbsp;<b>$m_time</font></b></TD></TR>

						
						</TABLE><p><p>
</center>

(END HTML FOOTER)

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$DATA{'id'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"msg\" VALUE=\"/account2\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$DATA{'room'}\">\n<center><INPUT TYPE=\"submit\" VALUE=\" SUBMIT \"></center>\n\n";


print "\n</FORM>\n\n</body></html>\n";



dbmclose(%D);

################


exit;