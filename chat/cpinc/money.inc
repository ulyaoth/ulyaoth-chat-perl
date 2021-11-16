#!/usr/bin/perl



dbmopen(%O,"$root/ops/ops/$DATA{'ops'}",0777);

if($O{'level'} < $staff_rank){

$error = "Control Panel, please login!";

require "$root/cpinc/login.inc";

dbmclose(%O);
exit;

}
dbmclose(%O);


dbmopen(%N,"$root/ops/ops/$DATA{'ops'}",0777);

print <<"(END HTML FOOTER)";


<html>
<head>
<title>$title</title>
</head>
<body bgcolor="#000000" text="#ffffff">
<table border="0" cellpadding="0" cellspacing="4">

<center>

$N{'total_ops'}

<p>

Total Money: \$ $N{'total_money'}. Has Money: \$ $N{'total_has'}. Total Accounts: <b>$N{'total_accounts'}</b>. Total renewals: <b>$N{'total_renewals'}.</b>.



</table>
</body>
</html>

(END HTML FOOTER)


dbmclose(%N);

return true;
