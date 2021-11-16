#!/usr/bin/perl

if(!$DATA{'b'}){

dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);


print <<"(END HTML FOOTER)";

<html>
<head>
</head>
<body>
<form method="POST" action="cp.cgi">
<center><i><font color="#FF0000"><font size=+5>Account Information</font></font></i></center>
<blockquote>
<blockquote><b><u><font color="#000000">Fixed Information:</font></u></b>
<br><b><font color="#3333FF">Nick:</font></b><font color="#000000"> $DATA{'ops'}</font>
<br><b><font color="#3333FF">Rank:</font></b><font color="#000000"> $USER{'level'}</font>
<br><b><font color="#3333FF">Ops id:</font></b><font color="#000000"> $USER{'id'}</font>
<br><b><font color="#3333FF">Starts On:</font></b><font color="#000000"> $USER{'ops_began'}</font>
<br><b><font color="#3333FF">Ends On:</font></b><font color="#000000"> $USER{'ops_end'}</font>
<br><b><font color="#3333FF">Op Since:</font></b><font color="#000000"> $USER{'ops_since'}</font></blockquote>

</blockquote>
<blockquote>
<blockquote><b><u><font color="#000000">Variable Information:</font></u></b>
<TABLE>
<TR>
<TD><b><font color="#3333FF">Hint Word:</font></b></TD><TD WIDTH="5%"></TD><TD><input type="text" name="hint" value="$USER{'hint'}" SIZE="20" MAXLENGTH="15"></TD>
</TR>
<TR>
<TD><b><font color="#3333FF">Registered E-Mail:</font></b></TD><TD></TD><TD><input type="text" name="email" value="$USER{'email'}" SIZE="20" MAXLENGTH="30"></TD>
</TR>
<TR>
<TD><input type="submit" value="Update Information"></TD><TD></TD><TD></TD>
</TR>
</TABLE>
</blockquote>
</blockquote>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="account" name="a">

</form>
</body>
</html>

(END HTML FOOTER)

dbmclose(%USER);

return true;

}else{


dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);


if($USER{'hint'} ne $DATA{'hint'}){

$r = "Updated";;

$USER{'hint'} = $DATA{'hint'};

    open(MAIL,"|$sendmail -t");
    print MAIL "To: $DATA{'email'}\n";
    print MAIL "From: webmaster\@ulyaoth.com (control panel)\n";
    print MAIL "Subject: $DATA{'n'}\n\n$DATA{'icq_message'}\n";
    print MAIL "This is a notice for you that you used the Members Control Panel to update your account information.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Your new hint word will be: $DATA{'hint'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Ulyaoth Chat! Admin\n https:\/\/chat.ulyaoth.com\n";
    close(MAIL);
}

if($USER{'email'} ne $DATA{'email'}){

$USER{'email'} = $DATA{'email'};

$rr = "Updated";;


    open(MAIL,"|$sendmail -t");
    print MAIL "To: $DATA{'email'}\n";
    print MAIL "From: webmaster\@ulyaoth.com (control panel)\n";
    print MAIL "Subject: Ulyaoth Chat Ops Account!\n";
    print MAIL "This is a notice for you that you used the Members Control Panel to update your account information.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Your new registered e-mail address will be $DATA{'email'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Ulyaoth Chat! Admin\n https:\/\/chat.ulyaoth.com\n";
    close(MAIL);


}

dbmclose(%USER);


##


dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);


print <<"(END HTML FOOTER)";

<html>
<head>
</head>
<body>
<form method="POST" action="cp.cgi">
<center><i><font color="#FF0000"><font size=+5>Account Information</font></font></i></center>
<blockquote>
<blockquote><b><u><font color="#000000">Fixed Information:</font></u></b>
<br><b><font color="#3333FF">Nick:</font></b><font color="#000000"> $DATA{'ops'}</font>
<br><b><font color="#3333FF">Rank:</font></b><font color="#000000"> $USER{'level'}</font>
<br><b><font color="#3333FF">Ops id:</font></b><font color="#000000"> $USER{'id'}</font>
<br><b><font color="#3333FF">Starts On:</font></b><font color="#000000"> $USER{'ops_began'}</font>
<br><b><font color="#3333FF">Ends On:</font></b><font color="#000000"> $USER{'ops_end'}</font>
<br><b><font color="#3333FF">Op Since:</font></b><font color="#000000"> $USER{'ops_since'}</font></blockquote>

</blockquote>
<blockquote>
<blockquote><b><u><font color="#000000">Variable Information:</font></u></b>
<TABLE>
<TR>
<TD><b><font color="#3333FF">Hint Word:</font></b></TD><TD WIDTH="5%"></TD><TD><input type="text" name="hint" value="$USER{'hint'}" SIZE="20" MAXLENGTH="15">$r</TD>
</TR>
<TR>
<TD><b><font color="#3333FF">Registered E-Mail:</font></b></TD><TD></TD><TD><input type="text" name="email" value="$USER{'email'}" SIZE="20" MAXLENGTH="30">$rr</TD>
</TR>
<TR>
<TD><input type="submit" value="Update Information"></TD><TD></TD><TD></TD>
</TR>
</TABLE>
</blockquote>
</blockquote>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="account" name="a">

</form>
</body>
</html>

(END HTML FOOTER)


dbmclose(%USER);

return true;

}











