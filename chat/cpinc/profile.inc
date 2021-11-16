#!/usr/bin/perl

if(!$DATA{'b'}){

dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);


print <<"(END HTML FOOTER)";

<html>
<head>
</head>
<body>
<form method="POST" action="cp.cgi">
<center><font size=+5 color=#0000FF><i>Profile</i></font></center>
<blockquote><blockquote>
<TABLE>
<TR>
<TD WIDTH="20%"><B><font color="#FF0000">Nickname:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="nick" size="15" maxlength="15" value="$USER{'prof_nick'}"></TD>
</TR>
<TR><TD><B><font color="#FF0000">Age:</B></font></TD><TD>&nbsp;</TD><TD><SELECT NAME="age">

<OPTION VALUE="$USER{'prof_age'}" SELECTED>$USER{'prof_age'}
<OPTION VALUE="10-">10-
<OPTION VALUE="11">11
<OPTION VALUE="12">12
<OPTION VALUE="13">13
<OPTION VALUE="14">14
<OPTION VALUE="15">15
<OPTION VALUE="16">16
<OPTION VALUE="17">17
<OPTION VALUE="18">18
<OPTION VALUE="19">19
<OPTION VALUE="20">20
<OPTION VALUE="21">21
<OPTION VALUE="22">22
<OPTION VALUE="23">23
<OPTION VALUE="24">24
<OPTION VALUE="25">25
<OPTION VALUE="26">26
<OPTION VALUE="27">27
<OPTION VALUE="28">28
<OPTION VALUE="29">29
<OPTION VALUE="30">30
<OPTION VALUE="31">31
<OPTION VALUE="32">32
<OPTION VALUE="33">33
<OPTION VALUE="34">34
<OPTION VALUE="35">35
<OPTION VALUE="36">36
<OPTION VALUE="37">37
<OPTION VALUE="38">38
<OPTION VALUE="39">39
<OPTION VALUE="40+">40+
</SELECT></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Gender:</B></font></TD><TD>&nbsp;</TD><TD>

<SELECT NAME="gender">
<OPTION VALUE="$USER{'prof_gender'}" SELECTED>$USER{'prof_gender'}
<OPTION VALUE="male">male
<OPTION VALUE="female">female
</SELECT>

</TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Material Status:</B></font></TD><TD>&nbsp;</TD><TD>

<SELECT NAME="material">
<OPTION VALUE="$USER{'prof_material'}" SELECTED>$USER{'prof_material'}
<OPTION VALUE="single">single
<OPTION VALUE="married">married
<OPTION VALUE="seperated">seperated
<OPTION VALUE="divorced">divorced
</SELECT>

</TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Occupation:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="occ" MAXLENGTH="30" value="$USER{'prof_occ'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Nationality:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="nat" MAXLENGTH="30" value="$USER{'prof_nat'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Currently Living in:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="cur" MAXLENGTH="30" value="$USER{'prof_cur'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">E-mail Address:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="email" MAXLENGTH="30" value="$USER{'email'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Homepage URL:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="homepage" MAXLENGTH="70" value="$USER{'prof_homepage'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Personal Quote:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="quote" MAXLENGTH="550" value="$USER{'prof_quote'}"></TD>
</TR>
<TR>
<TD></TD><TD></TD><TD><input type="submit" value="Update Profile Information"></TD>
</TR>
</TABLE>
</blockquote></blockquote>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="profile" name="a">

</form>
</body>
</html>

(END HTML FOOTER)

dbmclose(%USER);

return true;

}else{

$r = 0;

dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);


if($USER{'prof_nick'} ne $DATA{'nick'}){

$USER{'prof_nick'} = $DATA{'nick'};

$r++;
}

if($USER{'email'} ne $DATA{'email'}){

$USER{'email'} = $DATA{'email'};

$r++;
}

if($USER{'prof_occ'} ne $DATA{'occ'}){

$USER{'prof_occ'} = $DATA{'occ'};

$r++;
}

if($USER{'prof_age'} ne $DATA{'age'}){

$USER{'prof_age'} = $DATA{'age'};

$r++;
}

if($USER{'prof_gender'} ne $DATA{'gender'}){

$USER{'prof_gender'} = $DATA{'gender'};

$r++;
}

if($USER{'prof_material'} ne $DATA{'material'}){

$USER{'prof_material'} = $DATA{'material'};

$r++;
}

if($USER{'prof_nat'} ne $DATA{'nat'}){

$USER{'prof_nat'} = $DATA{'nat'};

$r++;
}


if($USER{'prof_cur'} ne $DATA{'cur'}){

$USER{'prof_cur'} = $DATA{'cur'};

$r++;
}


if($USER{'prof_homepage'} ne $DATA{'homepage'}){

$USER{'prof_homepage'} = $DATA{'homepage'};

$r++;
}

if($USER{'prof_quote'} ne $DATA{'quote'}){

$USER{'prof_quote'} = $DATA{'quote'};

$r++;
}



dbmclose(%USER);


##

dbmopen(%USER,"$root/ops/ops/$DATA{'ops'}",0777);


print <<"(END HTML FOOTER)";



<html>
<head>
</head>
<body>
<form method="POST" action="cp.cgi">
<center><font size=+5 color=#0000FF><i>Profile</i></font></center>

(END HTML FOOTER)

if($r > 0){

print "<center>===========================<br><i>Updated!</i><br>===========================</center>";
}


print <<"(END HTML FOOTER)";


<blockquote><blockquote>
<TABLE>
<TR>
<TD WIDTH="20%"><B><font color="#FF0000">Nickname:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="nick" size="15" maxlength="15" value="$USER{'prof_nick'}"></TD>
</TR>
<TR><TD><B><font color="#FF0000">Age:</B></font></TD><TD>&nbsp;</TD><TD><SELECT NAME="age">

<OPTION VALUE="$USER{'prof_age'}" SELECTED>$USER{'prof_age'}
<OPTION VALUE="10-">10-
<OPTION VALUE="11">11
<OPTION VALUE="12">12
<OPTION VALUE="13">13
<OPTION VALUE="14">14
<OPTION VALUE="15">15
<OPTION VALUE="16">16
<OPTION VALUE="17">17
<OPTION VALUE="18">18
<OPTION VALUE="19">19
<OPTION VALUE="20">20
<OPTION VALUE="21">21
<OPTION VALUE="22">22
<OPTION VALUE="23">23
<OPTION VALUE="24">24
<OPTION VALUE="25">25
<OPTION VALUE="26">26
<OPTION VALUE="27">27
<OPTION VALUE="28">28
<OPTION VALUE="29">29
<OPTION VALUE="30">30
<OPTION VALUE="31">31
<OPTION VALUE="32">32
<OPTION VALUE="33">33
<OPTION VALUE="34">34
<OPTION VALUE="35">35
<OPTION VALUE="36">36
<OPTION VALUE="37">37
<OPTION VALUE="38">38
<OPTION VALUE="39">39
<OPTION VALUE="40+">40+
</SELECT></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Gender:</B></font></TD><TD>&nbsp;</TD><TD>


<SELECT NAME="gender">
<OPTION VALUE="$USER{'prof_gender'}" SELECTED>$USER{'prof_gender'}
<OPTION VALUE="male">male
<OPTION VALUE="female">female
</SELECT>

</TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Material Status:</B></font></TD><TD>&nbsp;</TD><TD>

<SELECT NAME="material">
<OPTION VALUE="$USER{'prof_material'}" SELECTED>$USER{'prof_material'}
<OPTION VALUE="single">single
<OPTION VALUE="married">married
<OPTION VALUE="seperated">seperated
<OPTION VALUE="divorced">divorced
</SELECT>

</TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Occupation:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="occ" MAXLENGTH="30" value="$USER{'prof_occ'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Nationality:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="nat" MAXLENGTH="30" value="$USER{'prof_nat'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Currently Living in:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="cur" MAXLENGTH="30" value="$USER{'prof_cur'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">E-mail Address:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="email" MAXLENGTH="30" value="$USER{'email'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Homepage URL:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="homepage" MAXLENGTH="70" value="$USER{'prof_homepage'}"></TD>
</TR>
<TR>
<TD><B><font color="#FF0000">Personal Quote:</B></font></TD><TD>&nbsp;</TD><TD><input type="text" name="quote" MAXLENGTH="550" value="$USER{'prof_quote'}"></TD>
</TR>
<TR>
<TD></TD><TD></TD><TD><input type="submit" value="Update Profile Information"></TD>
</TR>
</TABLE>
</blockquote></blockquote>

<input type="hidden" value="$DATA{'ops'}" name="ops">

<input type="hidden" value="$DATA{'s'}" name="s">

<input type="hidden" value="yes" name="b">

<input type="hidden" value="profile" name="a">

</form>
</body>
</html>




(END HTML FOOTER)


dbmclose(%USER);

return true;

}











