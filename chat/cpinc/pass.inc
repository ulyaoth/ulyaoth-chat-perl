#!/usr/bin/perl

if(!$DATA{'b'}){


print <<"(END HTML FOOTER)";

<html>
<head>
<title>Ulyaoth Chat!</title>
</head>
<body>
<center><br><i><font size="+5" color="#FF0000">Change Password</font></i></center>
<blockquote>
  <blockquote>
    
    <form method="POST" action="cp.cgi">
     
<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="pass" name="a">

      <table border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td><strong>Current Password:</strong></td>
          <td width="10"></td>
          <td><input type="password" name="p" size="20" maxlength="15"></td>
        </tr>
        <tr>
          <td><strong>New Password:</strong></td>
          <td></td>
          <td><input type="password" name="p1" size="20" maxlength="15"></td>
        </tr>
        <tr>
          <td><strong>New Password Again:</strong></td>
          <td></td>
          <td><input type="password" name="p2" size="20" maxlength="15"></td>
        </tr>
        <tr>
          <td></td>
          <td></td>
          <td><input type="submit" value="Submit / Change password"></td>
        </tr>
      </table>
    </form>
  </blockquote>
</blockquote>
</body>
</html>

(END HTML FOOTER)


return true;

}else{


if(!$DATA{'p'} or !$DATA{'p1'} or !$DATA{'p2'}){

$er = "Error, all fields are required.";

}


if($DATA{'p1'} ne $DATA{'p2'}){

$er = "Error, passwords do not match.";

}

dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);

if($USER{'realpassword'} ne $DATA{'p'}){

$er = "Error, incorrect password.";

}
dbmclose(%USER);


if($er){


print <<"(END HTML FOOTER)";

<html>
<head>
<title>Ulyaoth Chat!</title>
</head>
<body>
<center><br><i><font size="+5" color="#FF0000">Change Password</font></i></center>
<blockquote>
  <blockquote>
    <center>$er</center>
    <form method="POST" action="cp.cgi">
     
<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="pass" name="a">

      <table border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td><strong>Current Password:</strong></td>
          <td width="10"></td>
          <td><input type="password" name="p" size="20" maxlength="15"></td>
        </tr>
        <tr>
          <td><strong>New Password:</strong></td>
          <td></td>
          <td><input type="password" name="p1" size="20" maxlength="15"></td>
        </tr>
        <tr>
          <td><strong>New Password Again:</strong></td>
          <td></td>
          <td><input type="password" name="p2" size="20" maxlength="15"></td>
        </tr>
        <tr>
          <td></td>
          <td></td>
          <td><input type="submit" value="Submit / Change password"></td>
        </tr>
      </table>
    </form>
  </blockquote>
</blockquote>
</body>
</html>

(END HTML FOOTER)

return true;
exit;

}else{


dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);

    open(MAIL,"|$sendmail -t");
    print MAIL "To: $USER{'email'}\n";
    print MAIL "From: webmaster\@ulyaoth.com (control panel)\n";
    print MAIL "Subject: Ulyaoth Chat Ops Account!\n";
    print MAIL "This is a notice for you that you used the Members Control Panel to update your account information.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Old Password: $USER{'realpassword'}\n";
    print MAIL "New Password: $DATA{'p1'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Ulyaoth Chat! Admin\n https:\/\/chat.ulyaoth.com\n";
    close(MAIL);


$USER{'realpassword'} = $DATA{'p1'};

$passw = crypt($DATA{'p1'}, "Cd");

$USER{'password'} = $passw;

dbmclose(%USER);



print <<"(END HTML FOOTER)";

<html>

<head>
<title>Saqer Chat!</title>
</head>
<body>

<center>Approved: Password successfuly changed</center>

</body></html>

(END HTML FOOTER)


return true;


}
}











