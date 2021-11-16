#!/usr/bin/perl

$time = time();  


@months = ('January','February','March','April','May','June','July','August','September','October','November','December');  @days = ('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');  

($sec,$min,$hour,$day,$month,$year,$day2) = (localtime(time))[0,1,2,3,4,5,6];  


if ($sec < 10) { $sec = "0$sec"; }  

if ($min < 10) { $min = "0$min"; }  


if ($hour < 10) { $hour = "0$hour"; }  


if ($day < 10) { $day = "0$day"; }  


$year += "1900";  $weekday = $days[$day2];              

$amonth = $months[$month];   

$fulltime = "$weekday, $amonth $day, $year, $hour:$min:$sec";   



print "Content-type: text/html\n\n";

if(!$DATA{'c'} or !$DATA{'message'} or !-e "$root/ops/ops/$DATA{'b'}"){

print <<"(END HTML FOOTER)";

<center><font size=+5 color=#FF0000><i>Send New ChatMail</i></font></center>

<form method="POST" action="cp.cgi">
<div align="center">
<table border="0" cellpadding="0" cellspacing="0">
<tr>
      <td>To: </td>
      <td width="10"></td>
      <td><input type="text" name="b" value="$DATA{'b'}" SIZE="20" MAXLENGTH="15"></td>
</tr>
<tr>
      <td ALIGN=LEFT VALIGN=TOP>Message: </td>
      <td width="10"></td>
      <td><textarea name="message" value="" rows=5 cols=40 wrap=virtual></textarea></td>
</tr>
<tr>
      <td></td>
      <td></td>
      <td><input type="submit" name="send" value="Send Chat Mail">
      <input type="reset" value="Clear"></td>
</tr>
</table>
<br><i>To avoid flooding, only 550 characters of your chatmail message will be sent!</i>
   
<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="c">

<input type="hidden" value="sendmail" name="a">

</form>
(END HTML FOOTER)

return true;

}else{


open(MAILIG,"$root/mail/igmail/$DATA{'b'}.txt");



@igmail = <MAILIG>;



close(MAILIG);



foreach $line(@igmail){



chop($line);



if($line eq $DATA{'ops'}){



print " Error , Ops <b>$DATA{'b'}</b> is ignoring your Chat Mails.";



return true;



exit;



}}



dbmopen(%MAIL,"$root/opspreferences/$DATA{'b'}",0777);



$MAIL{'mail_inbox'}++;



$MAIL{'mail_new'}++;



$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>$MAIL{'mail_inbox'}</b>. <font color=\"red\">New: <b>$MAIL{'mail_new'}</b>.</font> Please use /mail to read cmail and set your options, /mail [nick] to send.";



dbmclose(%MAIL);





for (0..9) { $cid .= pack("C",65+int(rand(25.99))); }



open(CMAIL,">>$root/mail/$DATA{'b'}.txt");



flock(CMAIL,2);


$DATA{'message'} =~ s/\n+//ig;

$DATA{'message'} =~ s/\<//ig;

$DATA{'message'} =~ s/\>//ig;

$DATA{'message'} =~ s/\s+\s+/ /ig;


print CMAIL "$cid\|\"\'\|$DATA{'ops'}\|\"\'\| <!-- $cid --> <b>$opsid \*$DATA{'ops'}\*</b> ($ENV{'REMOTE_ADDR'}) $fulltime.<br> $DATA{'message'}<p>\n"; 



close(CMAIL); 




print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#ffffff" text="#000000">

(END HTML FOOTER)

open(CHECKCMAIL,"$root/mail/$DATA{'ops'}.txt");

@checkcmail = <CHECKCMAIL>;

foreach $line(@checkcmail){

($c1,$c2,$c3)=split(/\|\"\'\|/,$line);


$c3 =~ s/^\s+//ig;

$c3 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

print "<b>OPTIONS: <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=del&b=$c1\">DEL</a> | <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=addwait&b=$c2\">Add WAIT</a> | <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=sendmail&b=$c2\">REPLAY</a></b><br>\n $c3\n\n<hr>";

}

print "<center><p>Your chat mail has been sent to Operator <b>$DATA{'b'}</b>. Time: $fulltime.</center>";
print "</body>\n</html>";

return true;



return true;
}