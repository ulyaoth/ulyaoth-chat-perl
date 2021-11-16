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
<center><font size=+3 color=#FF0000><i>Check Ops Application/Create Account</i></font></center>
<form method="POST" action="cp.cgi">
  <div align="center"><center><p>Input Application Code:<br>
  <input type="text" name="b" size="20" maxlength="40"></p>
  </center></p>
  </center></div><div align="center"><center><p><input type="submit" value="Check"></p>
  </center></div>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="create" name="a">
</form>
</body>
</html>


(END HTML FOOTER)

exit;

}


if($DATA{'b'} && !$DATA{'c'}){


if(!-e "$root/app/$DATA{'b'}"){


print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title Chat!</title>
</head>
<body>
<center><font size=+3 color=#FF0000><i>Check Ops Application/Create Account</i></font>\n<p>Error, application with code <b>$DATA{'b'}</b> not found.<p></center>
<form method="POST" action="cp.cgi">
  <div align="center"><center><p>Input Application Code:<br>
  <input type="text" name="b" size="20" maxlength="40"></p>
  </center></p>
  </center></div><div align="center"><center><p><input type="submit" value="Check"></p>
  </center></div>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="create" name="a">
</form>
</body>
</html>


(END HTML FOOTER)

exit;
}





dbmopen(%O,"$root/app/$DATA{'b'}",0777);


if(-e "$root/ops/ops/$O{'application'}"){

$taken = "(nickname is taken by another Op.)";

}

print <<"(END HTML FOOTER)";


<head><title>$title Chat</title>
</head>

<body><center><b>Application with code <b>$DATA{'b'}</b>.</b></center><p><p>
<center><table width=500><tr><td>

<FORM METHOD="POST" NAME="msg" ACTION="cp.cgi">

<b>Nickname : <font color="red">$O{'application'} $taken</font></b><p>
$O{'level'} - Rank<p>
$O{'id'} - Ops id<p>
$O{'realpassword'} - Password<p>
$O{'name'} - Name<p>
$O{'surname'} - Surname<p>
$O{'country'} - Country<p>
$O{'zipcode'} - Zip code<p>
$O{'street'} - Street<p>
$O{'phone'} - Phone number<p>
$O{'email'} - Email address<p>
<INPUT type="hidden" name="c" value="yes"><p>
<INPUT type="hidden" name="b" value="$DATA{'b'}"><p>

</table>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="create" name="a">

<br><INPUT TYPE=SUBMIT VALUE="  ADD/ACCOUNT  "> || <b><a href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=create"> ABORT</a><b><br></body>

(END HTML FOOTER)

dbmclose(%O);

exit;

}

#


($sec,$min,$hour,$day,$month,$year,$day2) = (localtime(time))[0,1,2,3,4,5,6];  

if ($sec < 10) { $sec = "0$sec"; }  

if ($min < 10) { $min = "0$min"; }  

if ($hour < 10) { $hour = "0$hour"; }  

if ($day < 10) { $day = "0$day"; }  

$year += "1900";  $weekday = $days[$day2];              

$emonth = $month + 1; 

dbmopen(%US,"$root/app/$DATA{'b'}",0777);

$le = $US{'length'};

dbmclose(%US);


$cmonth = $emonth + $le;

$start = "$day\/$emonth\/$year";    


if($cmonth > 24){

$cmonth = $cmonth - 24;

$year = $year + 2;

}


if($cmonth > 12){

$cmonth = $cmonth - 12;

$year = $year + 1;

}

$end = "$day\/$cmonth\/$year";    

dbmopen(%US,"$root/app/$DATA{'b'}",0777);


    open(MAIL,"|$sendmail -t");
    print MAIL "To: $US{'email'}\n";
    print MAIL "From: webmaster\@ulyaoth.com (Ulyaoth Chat Admin)\n";
    print MAIL "Subject: Ulyaoth Chat Membership!\n";
    print MAIL "You have a new account with us with the following information, please do NOT print this email or forward to someone else.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Nick: $US{'application'}\n";
    print MAIL "Password: $US{'realpassword'}\n";
    print MAIL "Email: $US{'email'}\n";
    print MAIl "Account started on $start for $US{'length'} motnh(s) ending $end.\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Ulyaoth Chat! Admin\n https:\/\/chat.ulyaoth.com\n";
    close(MAIL);


$US{'ops_began'} = $start;

$US{'ops_since'} = $start;

$US{'ops_end'} = $end;

$len = $US{'length'};

$application = $US{'application'};

dbmclose(%US);

rename("$root/app/$DATA{'b'}","$root/ops/ops/$application");

dbmopen(%ME,"$root/ops/ops/$DATA{'ops'}",0777);

open(MAIL,"|$sendmail -t");

   





if($len == 1){

$ME{'total_money'} = $ME{'total_money'} + 0;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$application \|\| \$0 \|\| $start";

$ME{'total_accounts'} = $ME{'total_accounts'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 0;

}elsif($len == 3){

$ME{'total_money'} = $ME{'total_money'} + 15;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$application \|\| \$15 \|\| $start";

$ME{'total_accounts'} = $ME{'total_accounts'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 15;

}elsif($len == 6){

$ME{'total_money'} = $ME{'total_money'} + 30;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$application \|\| \$30 \|\| $start";

$ME{'total_accounts'} = $ME{'total_accounts'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 30;

}elsif($len == 9){

$ME{'total_money'} = $ME{'total_money'} + 45;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$application \|\| \$45 \|\| $start";

$ME{'total_accounts'} = $ME{'total_accounts'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 45;

}elsif($len == 12){

$ME{'total_money'} = $ME{'total_money'} + 55;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$application \|\| \$55 \|\| $start";

$ME{'total_accounts'} = $ME{'total_accounts'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 55;

}elsif($len == 24){

$ME{'total_money'} = $ME{'total_money'} + 100;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$application \|\| \$100 \|\| $start";

$ME{'total_accounts'} = $ME{'total_accounts'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 100;
}

print <<"(END HTML FOOTER)";


<head><title>$title Chat</title>
</head>

<body><center><b>Operator <b><font color=red>$application</font></b> successfuly added in Ops database.</b></center><p><p>

Length: $len month(s).<br>
Ending: $end.<br>
Rank    1.<br>



</body>
</html>

(END HTML FOOTER)





return true;
