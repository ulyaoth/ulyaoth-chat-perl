#!/usr/bin/perl
print "Content-type: text/html\n\n";


print <<"(END HTML FOOTER)";
<html>
<body>
<br>
<center><font size=+5 color=#FF0000><i>Online</i></font>
<blockquote><table border="0" cellpadding="0" cellspacing="0">
<tr>
<td nowrap><b>Nick</b></td>
<td width="15" nowrap></td>
<td nowrap><b>Ip Address</b></td>
<td width="15" nowrap></td>
<td nowrap><b>Room</b></td>
<td width="15" nowrap></td>
<td nowrap><b>Comment</b></td>
<td width="15" nowrap></td>
<td nowrap></td>
</tr>

(END HTML FOOTER)

$c = 0;

opendir(DIR, "$root/online/users");

flock(DIR,2);

@dir = readdir(DIR);

close(DIR);


foreach $u (sort @dir){

if($u ne '.' && $u ne '..'){

$u =~ s/.db//;

dbmopen(%U,"$root/online/users/$u",0777);

if ($U{'level'} >= 1 && $U{'level'} < $comm_rank) {

$color = "#0000FF";

}elsif ($U{'level'} >= $comm_rank && $U{'level'} < $staff_rank) {

$color = "#CC0099";

}elsif ($U{'level'} >= $staff_rank && $U{'level'} < $admin_rank) {

$color = "#336633";

}elsif ($U{'level'} >= $admin_rank) {

$color = "#FF6600";

}else{

$color = "#000000";

}

$c++;

print "<tr>\n";

print "<td nowrap><font color=\"$color\">$u</font></td>\n";

print "<td width=\"15\" nowrap></td>\n";

print "<td nowrap><font color=\"$color\">$U{'ip'}</font></td>\n";

print "<td width=\"15\" nowrap></td>\n";

print "<td nowrap><font color=\"$color\">$U{'room'}</font></td>\n";
print "<td width=\"15\" nowrap></td>";
print "<td nowrap><font color=\"$color\">$U{'comment'}</font></td>\n";
print "<td width=\"15\" nowrap></td>";
print "<td nowrap><font color=\"$color\">$U{'mode'}</font></td>";
print "</tr>\n";


dbmclose(%U);

		}

}


print <<"(END HTML FOOTER)";


</table></blockquote>
<br>There are currently <b>$c</b> chatters online.<br><br></center>

</body></html>


(END HTML FOOTER)


return true;











