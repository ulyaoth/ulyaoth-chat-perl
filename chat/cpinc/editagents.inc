#!/usr/bin/perl


dbmopen(%O,"$root/ops/ops/$DATA{'ops'}",0777);

if($O{'level'} < $staff_rank){

$error = "Control Panel, please login!";

require "$root/cpinc/login.inc";

dbmclose(%O);
exit;

}
dbmclose(%O);


if(!$DATA{'c'}){

dbmopen(%N,"$root/ops/ops/$DATA{'b'}",0777);

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View/Edit Agents Information</center><p>
<FORM METHOD=\"POST\" ACTION=\"cp.cgi\">

<table border="0" cellpadding="0" cellspacing="4" align="center">
<center>
<b>nickname: <font color=red>$DATA{'b'}</font></b><p>
<b>id: <font color=red>$N{'id'}</font></b><p>
<b>rank: <font color=red>$N{'level'}</font></b><p>
<b>ops since: <font color=red>$N{'ops_since'}</font></b><p>
<b>street: <font color=red>$N{'street'}</font></b><p>
<b>country: <font color=red>$N{'country'}</font></b><p>
<b>list of accounts:<br> <b>$N{'total_ops'}</b><p>
<b>total money: <font color=red>$N{'total_money'}</font></b><p>
<b>created accounts: <font color=red>$N{'total_accounts'}</font></b><p>
Has money:<input type="text" size=3 value="\$ $N{'total_has'}" name="has">

<center><p><input type="submit" value="Update / Edit">
</center>
<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="editagents" name="a">

<input type="hidden" value="$DATA{'b'}" name="b">

<input type="hidden" value="yes" name="c">


</form>
</center>

</table>
</body>
</html>

(END HTML FOOTER)
dbmclose(%N);

}else{


$DATA{'has'} =~ s/[^\w]//g;

dbmopen(%N,"$root/ops/ops/$DATA{'b'}",0777);

if($DATA{'has'} > $N{'total_has'} or !$DATA{'has'}){

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View/Edit Agents Information</center><p>
<FORM METHOD=\"POST\" ACTION=\"cp.cgi\">

<table border="0" cellpadding="0" cellspacing="4" align="center">
<center>
<b>nickname: <font color=red>$DATA{'b'}</font></b><p>
<b>id: <font color=red>$N{'id'}</font></b><p>
<b>rank: <font color=red>$N{'level'}</font></b><p>
<b>ops since: <font color=red>$N{'ops_since'}</font></b><p>
<b>street: <font color=red>$N{'street'}</font></b><p>
<b>country: <font color=red>$N{'country'}</font></b><p>
<b>list of accounts:<br> <b>$N{'total_ops'}</b><p>
<b>total money: <font color=red>$N{'total_money'}</font></b><p>
<b>created accounts: <font color=red>$N{'total_accounts'}</font></b><p>
Has money:<input type="text" size=3 value="\$ $N{'total_has'}" name="has">
<p>
<font color=red>Error, you specified amount bigger than previous.</font>
<p>
<center><p><input type="submit" value="Update / Edit">
</center>
<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="editagents" name="a">

<input type="hidden" value="$DATA{'b'}" name="b">

<input type="hidden" value="yes" name="c">


</form>
</center>

</table>
</body>
</html>

(END HTML FOOTER)



dbmclose(%N);

return true;

exit;

}


$N{'total_has'} = $DATA{'has'};

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View/Edit Agents Information</center><p>
<FORM METHOD=\"POST\" ACTION=\"cp.cgi\">

<table border="0" cellpadding="0" cellspacing="4" align="center">
<center>
<b>nickname: <font color=red>$DATA{'b'}</font></b><p>
<b>id: <font color=red>$N{'id'}</font></b><p>
<b>rank: <font color=red>$N{'level'}</font></b><p>
<b>ops since: <font color=red>$N{'ops_since'}</font></b><p>
<b>street: <font color=red>$N{'street'}</font></b><p>
<b>country: <font color=red>$N{'country'}</font></b><p>
<b>list of accounts:<br> <b>$N{'total_ops'}</b><p>
<b>total money: <font color=red>$N{'total_money'}</font></b><p>
<b>created accounts: <font color=red>$N{'total_accounts'}</font></b><p>
Has money:<input type="text" size=3 value="\$ $N{'total_has'}" name="has">
<p>
<font color=red>Updated.</font>
<p>
<center><p><input type="submit" value="Update / Edit">
</center>
<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="editagents" name="a">

<input type="hidden" value="$DATA{'b'}" name="b">

<input type="hidden" value="yes" name="c">


</form>
</center>

</table>
</body>
</html>

(END HTML FOOTER)


dbmclose(%N);

return true;

exit;
}