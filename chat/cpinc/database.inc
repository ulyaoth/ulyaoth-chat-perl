#!/usr/bin/perl



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
<title>$title Chat</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View Operators</center><p>

<table border="0" cellpadding="0" cellspacing="4" align="center">


<b>|| <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=ops\">VIEW OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=comm\">VIEW COMM OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=staff\">VIEW STAFF OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=admin\">VIEW ADMIN OPS</a> || </b>
(END HTML FOOTER)


#

 $c = 0;
$comm = 0;
$staff = 0;
$admin = 0;
$u = 0;

       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;

$u++;

dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= 1 && $OPER{'level'} < $comm_rank){

     $c++; 

}elsif($OPER{'level'} >= $comm_rank && $OPER{'level'} < $staff_rank){

$comm++;

}elsif($OPER{'level'} >= $staff_rank && $OPER{'level'} < $admin_rank){


$staff++;

}elsif($OPER{'level'} >= $admin_rank){

$admin++;

}



dbmclose(%OPER);





        }}

#

print "<p>TOTAL OPS: <b>$c</b>. COMM OPS: <b>$comm</b>. STAFF OPS: <b>$staff</b>. ADMINS: <b>$admin</b>.<p>\n";


print <<"(END HTML FOOTER)";

<center>

</table>
</body>
</html>


(END HTML FOOTER)

}else{


if($DATA{'b'} eq "ops"){



print <<"(END HTML FOOTER)";


<html>
<head>
<title>$title Chat</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View Operators</center><p>

<table border="0" cellpadding="0" cellspacing="4" align="center">


<b>|| <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=ops\">VIEW OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=comm\">VIEW COMM OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=staff\">VIEW STAFF OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=admin\">VIEW ADMIN OPS</a> || </b><p>
(END HTML FOOTER)


#

 $c = 0;
$comm = 0;
$staff = 0;
$admin = 0;
$u = 0;

       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;

$u++;

dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= 1 && $OPER{'level'} < $comm_rank){

     print "Operator <b>$stuff</b>. Rank <b>$OPER{'level'}</b>. Id <b>$OPER{'id'}</b>. Started <b>$OPER{'ops_began'}</b>. Ending <b>$OPER{'ops_end'}</b>.<br>\n";

}

dbmclose(%OPER);





        }}

#

print <<"(END HTML FOOTER)";

<center>

</table>
</body>
</html>


(END HTML FOOTER)
}

if($DATA{'b'} eq "comm"){




print <<"(END HTML FOOTER)";


<html>
<head>
<title>$title Chat</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View Operators</center><p>

<table border="0" cellpadding="0" cellspacing="4" align="center">


<b>|| <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=ops\">VIEW OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=comm\">VIEW COMM OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=staff\">VIEW STAFF OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=admin\">VIEW ADMIN OPS</a> || </b><p>
(END HTML FOOTER)


#

 $c = 0;
$comm = 0;
$staff = 0;
$admin = 0;
$u = 0;

       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;

$u++;

dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= $comm_rank && $OPER{'level'} < $staff_rank){

     print "Operator <b>$stuff</b>. Rank <b>$OPER{'level'}</b>. Id <b>$OPER{'id'}</b>. Started <b>$OPER{'ops_began'}</b>. Ending <b>$OPER{'ops_end'}</b>.<br>\n";

}

dbmclose(%OPER);





        }}

#

print <<"(END HTML FOOTER)";

<center>

</table>
</body>
</html>


(END HTML FOOTER)




return true;



}

if($DATA{'b'} eq "staff"){




print <<"(END HTML FOOTER)";


<html>
<head>
<title>$title Chat</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View Operators</center><p>

<table border="0" cellpadding="0" cellspacing="4" align="center">


<b>|| <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=ops\">VIEW OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=comm\">VIEW COMM OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=staff\">VIEW STAFF OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=admin\">VIEW ADMIN OPS</a> || </b><p>
(END HTML FOOTER)


#

 $c = 0;
$comm = 0;
$staff = 0;
$admin = 0;
$u = 0;

       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;

$u++;

dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= $staff_rank && $OPER{'level'} < $admin_rank){

     print "Operator <b>$stuff</b>. Rank <b>$OPER{'level'}</b>. Id <b>$OPER{'id'}</b>. Started <b>$OPER{'ops_began'}</b>. Ending <b>$OPER{'ops_end'}</b>.<br>\n";

}

dbmclose(%OPER);





        }}

#

print <<"(END HTML FOOTER)";

<center>

</table>
</body>
</html>


(END HTML FOOTER)




return true;

}


if($DATA{'b'} eq "admin"){


print <<"(END HTML FOOTER)";


<html>
<head>
<title>$title Chat</title>
</head>
<body bgcolor="#000000" text="#ffffff">

<p><center>View Operators</center><p>

<table border="0" cellpadding="0" cellspacing="4" align="center">


<b>|| <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=ops\">VIEW OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=comm\">VIEW COMM OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=staff\">VIEW STAFF OPS</a> || <a href=\"cp.cgi?ops=$DATA{'ops'}&s=$DATA{'s'}&a=database&b=admin\">VIEW ADMIN OPS</a> || </b><p>
(END HTML FOOTER)


#

 $c = 0;
$comm = 0;
$staff = 0;
$admin = 0;
$u = 0;

       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;

$u++;

dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= $admin_rank){

     print "Operator <b>$stuff</b>. Rank <b>$OPER{'level'}</b>. Id <b>$OPER{'id'}</b>. Started <b>$OPER{'ops_began'}</b>. Ending <b>$OPER{'ops_end'}</b>.<br>\n";

}

dbmclose(%OPER);





        }}

#

print <<"(END HTML FOOTER)";

<center>

</table>
</body>
</html>


(END HTML FOOTER)




return true;






}}