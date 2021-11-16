#!/usr/bin/perl

print <<"(END HTML FOOTER)";


<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" background="">
<table border="0" cellpadding="0" cellspacing="4">
<tr>
<td><center><font color=green face=arial><u>Control<br>Panel</u></font></center></td>
</tr>
<b>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=account" target="main">My Account</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=profile" target="main">My Profile</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=cmail" target="main">My ChatMail</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=pass" target="main">My Password</a></td>
</tr>

<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=complain" target="main">To Complain</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=online" target="main">List</a></td>
</tr>
(END HTML FOOTER)


dbmopen(%O,"$root/ops/ops/$DATA{'ops'}",0777);

if($O{'level'} >= $staff_rank){

print <<"(END HTML FOOTER)";
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=create" target="main">Create Op</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=renew" target="main">Renew Op</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=nchange" target="main">Nick Change</a></td>
</tr>

<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=money" target="main">Money Owed</a></td>
</tr>
(END HTML FOOTER)

}

if($O{'level'} >= $admin_rank){

print <<"(END HTML FOOTER)";

<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=agents" target="main">Agents</a></td>
</tr>
<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database" target="main">Database</a></td>
</tr>

(END HTML FOOTER)

}

dbmclose(%O);


print <<"(END HTML FOOTER)";

<tr>
<td bgcolor=#000000><a style="text-decoration: none; color: #FFFFFF" href="cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=out" target="_top">Log Out</a></td>
</tr>




</table>
</body>
</html>

(END HTML FOOTER)


return true;
