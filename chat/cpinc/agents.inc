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

<p><center>View/Edit Agents Information</center><p>

<table border="0" cellpadding="0" cellspacing="4">

<center>

(END HTML FOOTER)


 $c = 0;


       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;



         dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= $staff_rank){

        print "<b>*** Agent <font color=red>$stuff</font>. Level: $OPER{'level'}. Id: $OPER{'id'}. Total money: $OPER{'total_money'}. Has money: $OPER{'total_has'}. <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=editagents&b=$stuff\">EDIT/VIEW</a></b><br>\n";

$c++; 
       }

dbmclose(%OPER);





        }}

                

print "<p>TOTAL: <b>$c</b> agents.<br>\n";

print <<"(END HTML FOOTER)";


</table>
</body>
</html>

(END HTML FOOTER)


dbmclose(%N);

return true;
