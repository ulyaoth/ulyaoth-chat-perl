#!/usr/bin/perl

print "Content-type: text/html\n\n";

($sec,$min,$hour,$day,$month,$year,$day2) = (localtime(time))[0,1,2,3,4,5,6];  

if ($day < 10) { $day = "0$day"; }  

$year += "1900";         

$emonth = $month + 1; 





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
<center><font size=+3 color=#FF0000><i>Check Ops Application/RENEWAL</i></font></center>
<form method="POST" action="cp.cgi">

  <div align="center"><center><p>Input Application Code:<br>
  <input type="text" name="b" size="20" maxlength="40"></p>
  </center></p>
  </center></div><div align="center"><center><p><input type="submit" value="Check"></p>
  </center></div>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="renew" name="a">
</form>
</body>
</html>


(END HTML FOOTER)

exit;

}


if($DATA{'b'} && !$DATA{'c'}){

if(!-e "$root/apprenew/$DATA{'b'}"){

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title Chat!</title>
</head>
<body>
<center><font size=+3 color=#FF0000><i>Check Ops Application/RENEWAL</i></font>\n<p>Error, application with code <b>$DATA{'b'}</b> not found.<p></center>
<form method="POST" action="cp.cgi">
  <div align="center"><center><p>Input Application Code:<br>
  <input type="text" name="b" size="20" maxlength="40"></p>
  </center></p>
  </center></div><div align="center"><center><p><input type="submit" value="Check"></p>
  </center></div>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="renew" name="a">
</form>
</body>
</html>


(END HTML FOOTER)

exit;
}


dbmopen(%O,"$root/apprenew/$DATA{'b'}",0777);

if($O{'renew_length'} == 1){

$money = "1 month. Free Trial Ops account.";

}elsif($O{'renew_length'} == 3){

$money = "3 months. 15 US Dollars.";

}elsif($O{'renew_length'} == 6){

$money = "6 months. 30 US Dollars.";

}elsif($O{'renew_length'} == 9){

$money = "9 months. 45 US Dollars.";

}elsif($O{'renew_length'} == 12){

$money = "12 months. 55 US Dollars.";

}elsif($O{'renew_length'} == 24){

$money = "24 months. 100 US Dollars.";

}


print <<"(END HTML FOOTER)";


<head><title>$title Chat</title>
</head>

<body><center><b>Application with code <b>$DATA{'b'}</b>.</b></center><p><p>
<center><table width=500><tr><td>

<FORM METHOD="POST" NAME="msg" ACTION="cp.cgi">

<b>Nickname : <font color="red">$O{'nickname'}</font></b><p>
$money<p>
<INPUT type="hidden" name="c" value="yes"><p>
<INPUT type="hidden" name="b" value="$DATA{'b'}"><p>

</table>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="renew" name="a">

<br><INPUT TYPE=SUBMIT VALUE="  SUBMIT/ RENEW ACCOUNT  "> || <b><a href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=renew"> ABORT</a><b><br></body>

(END HTML FOOTER)

dbmclose(%O);

exit;

}

#

###############################################



dbmopen(%US,"$root/apprenew/$DATA{'b'}",0777);

dbmopen(%S,"$root/ops/ops/$US{'nickname'}",0777);

($opsday,$opsmonth,$opsyear)=split(/\//,$S{'ops_end'});

dbmclose(%S);

$n = 0;


####

if($opsday >= $day && $opsmonth >= $emonth && $opsyear >= $year){

$n++;

}

#


if($n == 0){

$cmonth = $emonth + $US{'renew_length'};

$start = "$day\/$emonth\/$year";    

if($cmonth > 24){

$cmonth = $cmonth - 24;

$year = $year + 2;

}

if($cmonth > 12){

$cmonth = $cmonth - 12;

$year = $year + 1;

}


}else{

$cmonth = $opsmonth + $US{'renew_length'};

if($cmonth > 24){

$cmonth = $cmonth - 24;

$year = $opsyear + 2;

}

if($cmonth > 12){

$cmonth = $cmonth - 12;

$year = $opsyear + 1;

}

$day = $opsday;

}

$end = "$day\/$cmonth\/$year";    

#######################################

$US{'ops_end'} = $end;

dbmclose(%US);

#######RENEW

dbmopen(%APP,"$root/apprenew/$DATA{'b'}",0777);

dbmopen(%OP,"$root/ops/ops/$APP{'nickname'}",0777);

    open(MAIL,"|$sendmail -t");

    print MAIL "To: $OP{'email'}\n";
    print MAIL "From: webmaster\@ulyaoth.com (Ulyaoth Chat Admin)\n";
    print MAIL "Subject: Ulyaoth Chat Membership!\n";
    print MAIL "This is a notice that your Ops account has been renewed.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Nick: $APP{'nickname'}\n";
    print MAIL "Password: $OP{'realpassword'}\n";
    print MAIL "Email: $OP{'email'}\n";
    print MAIl "Account renewed for $APP{'renew_length'} motnh(s) ending on $APP{'ops_end'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Ulyaoth Chat! Admin\n https:\/\/chat.ulyaoth.com\n";
    close(MAIL);


$OP{'ops_end'} = $APP{'ops_end'};

if($n == 0){

$OP{'ops_began'} = $start;

$OP{'ops_months'} = $APP{'renew_length'};

}

$OP{'ops_months'} = $OP{'ops_months'} + $APP{'renew_length'};

dbmclose(%OP);

$j = $APP{'nickname'};

$len = $APP{'renew_length'};


dbmclose(%APP);



#################


dbmopen(%ME,"$root/ops/ops/$DATA{'ops'}",0777);

if($len == 3){

$ME{'total_money'} = $ME{'total_money'} + 15;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$j \|\| \$15 \|\| RENEWAL";

$ME{'total_renewals'} = $ME{'total_renewals'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 15;

}elsif($len == 6){

$ME{'total_money'} = $ME{'total_money'} + 30;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$j \|\| \$30 \|\| RENEWAL";

$ME{'total_renewals'} = $ME{'total_renewals'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 30;

}elsif($len == 9){

$ME{'total_money'} = $ME{'total_money'} + 45;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$j \|\| \$45 \|\| RENEWAL";

$ME{'total_renewals'} = $ME{'total_renewals'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 45;

}elsif($len == 12){

$ME{'total_money'} = $ME{'total_money'} + 55;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$j \|\| \$55 \|\| RENEWAL";

$ME{'total_renewals'} = $ME{'total_renewals'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 55;

}elsif($len == 24){

$ME{'total_money'} = $ME{'total_money'} + 100;

$ME{'total_ops'} = "$ME{'total_ops'}<br>\n$j \|\| \$100 \|\| RENEWAL";

$ME{'total_renewals'} = $ME{'total_renewals'} + 1;

$ME{'total_has'} = $ME{'total_has'} + 100;

}


dbmclose(%ME);


print <<"(END HTML FOOTER)";


<head><title>$title Chat</title>
</head>


<body><center><b>Operator <b><font color=red>$j</font></b> successfuly renewed for $len months.</b></center><p><p>

Length: $len month(s).<br>
Ending: $end.<br>

</body>
</html>

(END HTML FOOTER)


return true;

exit;


