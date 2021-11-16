#!/usr/bin/perl

print "Content-type: text/html\n\n";

if(!$DATA{'b'} or !$DATA{'themsg'}){

print <<"(END HTML FOOTER)";

<html>
<body>
<center><font size=+5 color=#FF0000><i>Complain</i></font></center>
<form method="POST" action="cp.cgi">
<blockquote><blockquote>
<table border="0" cellpadding="0" cellspacing="0">
<tr>
      <td>From: </td>
      <td width="10"></td>
      <td><b>$DATA{'ops'}</b> ip: $ENV{'REMOTE_ADDR'}</td>
</tr>
<tr>
      <td ALIGN=LEFT VALIGN=TOP>Message: </td>
      <td width="10"></td>
      <td><textarea name="themsg" rows=5 cols=40 wrap=virtual></textarea></td>
</tr>
<tr>
      <td></td>
      <td></td>
      <td><input type="submit" name="comp" value="Send Complaint"></td>
</tr>
</table>
<br><i>To avoid flooding, only 550 characters of your complaint message will be sent!</i>
</blockquote></blockquote>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="complain" name="a">
</form>
</body></html>

(END HTML FOOTER)


return true;

}else{

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

open(COMM,">>$root/boards/commbb.txt");

flock(COMM,2);

for (0..9) { $commid .= pack("C",65+int(rand(25.9999))); }


$DATA{'themsg'} = substr($DATA{'themsg'},0,550);


$DATA{'themsg'} =~ s/\n+//ig;

$DATA{'themsg'} =~ s/\<//ig;

$DATA{'themsg'} =~ s/\>//ig;

$DATA{'themsg'} =~ s/\s+\s+/ /ig;

print COMM "$commid\|\"\'\|<!-- $commid --> <b>$DATA{'ops'} ($DATA{'ops'}) from Control Panel</b> ($ENV{'REMOTE_ADDR'}) $fulltime<br> $DATA{'themsg'}<p>\n";

close(COMM);


print <<"(END HTML FOOTER)";

<html>
<body>
<p>&#32<p>
<center>Message sent, comm Ops will be informed, thank you. Time: $fulltime</center>


</body></html>

(END HTML FOOTER)

return true;

}