#!/usr/bin/perl


if($DATA{'frames'} eq "yes" or $frames eq "yes"){       

print "Content-type: text/html\n\n";

print "<html>\n<HEAD>\n<title>$title</title>\n";

print "<SCRIPT LANGUAGE=\"JavaScript\">
<!-- hide
B = new Array();
var b=0;
var s=0;
A = new Array();
A[0]='/help';
A[1]='/list';
// A[2]='/wait';
// A[3]='/frames';
// A[4]='/quit';\n";


$sss=5;

foreach$r(@rooms){

$sss++;

print "A[$sss]='/join $r';\n";

}


print "function set1() {
    if (document.myform.msg.value != null) {
	B[b]=document.myform.msg.value;
	b++;
	if (b > 50) { b = 0; }
	s=b;


document.myform2.msg.value=document.myform.msg.value;   
	document.myform2.submit();
	document.myform.msg.value=\"\";
	document.myform.msg.focus();
    } else {
	document.myform2.submit();
	document.myform.msg.focus();
    }
}
function set2() {
    document.myform.room.value='$room';
    document.myform.msg.value=\"\";
    document.myform.msg.focus();
}
function set4() {
    window.open(\"\",\"w\",\"height=250,width=125,toolbar=no,scrollbars=yes,resizable=yes\");
}
function out() {
    top.location=\"$location?room=$room&n=$DATA{'n'}&id=$DATA{'id'}&msg=/frames\";
}

function pomoc() {
    parent.frames[0].location=\"$location?room=$room&n=$DATA{'n'}&id=$DATA{'id'}&msg=/help\";
}

function ikone() {
    parent.frames[0].location=\"$location?room=$room&n=$DATA{'n'}&id=$DATA{'id'}&msg=/images\";
}

function bagit() {
    top.location=\"https://chat.ulyaoth.com\";
}
function quit() {
    top.location=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/quit\";
}

function set5() {
    if (document.myform.room.selectedIndex == 2) {
	set4();
    } else if (document.myform.room.selectedIndex == 3) {
	out();
    } else if (document.myform.room.selectedIndex == 4) {
	quit();
    } else if (document.myform.room.selectedIndex == 5) {
	bagit();
    } else {
	document.myform2.msg.value=A[document.myform.room.selectedIndex];
	document.myform2.submit();
	document.myform.msg.focus();
    }
}
function fw() {
    if (B[s]) {
	document.myform.msg.value=B[s];
    } else {
	s=0;
	document.myform.msg.value=B[s];
    }
    s++;
    if (s > 50) { s = 0; }
}
function cl() {
    s=b;
    document.myform.msg.value=\"\";
    document.myform.msg.focus();
}
function bk() {
    s--;
    if (s < 0) { s = 50; }
    if (B[s]) {
	document.myform.msg.value=B[s];
    }
}
// -->
</SCRIPT></HEAD>\n";


print "<BODY onLoad=\"set2()\" BGCOLOR=\"000000\" LINK=\"ddddff\" vlink=\"aaaaff\" TEXT=\"FFFFFF\">\n";

print "<center><nobr><FORM method=\"POST\"  target=\"display\" name=\"myform\" onSubmit=\"set1();return false\" action=\"$location\">\n";

print "<INPUT type=\"hidden\" name=\"n\" VALUE=\"$DATA{'n'}\">\n";

print "<INPUT type=\"hidden\" name=\"id\" VALUE=\"$DATA{'id'}\">\n";

print "<INPUT name=\"msg\" maxlength=450 size=75 type=\"text\" VALUE=\"\">\n";

print "<input type=button value=\"<\" onClick=\"bk()\"><input type=button value=\"||\" onClick=\"cl()\"><input type=button value=\">\" onClick=\"fw()\">\n";


print "<select name=\"room\" onChange=\"set5();return false\"> \n";

print "<option value=\"HELP\">HELP<option value=\"ROOM LIST\">ROOM LIST<option value=\"OPEN WAIT\">OPEN WAIT<option value=\"NO FRAME\">NO FRAME<option value=\"QUIT\">QUIT<option value=\"KILL/EXIT\">KILL/EXIT \n";



foreach $v (@rooms){

if($DATA{'room'} eq $v){

$g=1;

}}


if($g == 1){

foreach $key (@rooms){
          
if ($DATA{'room'} eq $key){

print "<OPTION VALUE=\"$key\" SELECTED style=\"background-color: #FFEDA3;\">$key\n";
            
}else{

print "<OPTION VALUE=\"$key\">$key\n";    

}}

}else{

foreach $z (@rooms){

print "<OPTION VALUE=\"$z\">$z\n";    

}

print "<OPTION VALUE=\"$room\" SELECTED style=\"background-color: #FFEDA3;\">$room\n";

}


print "</select>";

print " <input type=submit value=\"POST\"></form></nobr>";

print "<FORM method=\"POST\" name=\"myform2\" target=\"display\" action=\"$location\">";

print "<INPUT type=\"hidden\" name=\"n\" VALUE=\"$DATA{'n'}\">";

print "<INPUT type=\"hidden\" name=\"room\" VALUE=\"$room\">";

print "<INPUT type=\"hidden\" name=\"id\" VALUE=\"$DATA{'id'}\">";


print "<INPUT type=\"hidden\" maxlength=450 name=\"msg\" VALUE=\"\">";

print "<b> | <a href=\"\#\" onclick=\"pomoc()\;\"> Help </a> | <a href=\"\#\" onclick=\"out()\;\"> No Frames </a> | <a href=\"\/cgi-bin\/fhome\/cp.cgi\" target=_blank> Free Home</a> | <a href=\"\/cgi-bin\/fhome\/ops.cgi\" target=_blank> Sign Up </a> | <a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=\/im+1\" onClick=\"window.open('$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/im+1','w','height=500,width=645,toolbar=no,scrollbars=yes,resizable=yes')\" target=\"w\"> Images </a> |  <a href=\"\#\" onclick=\"quit()\;\">Quit </a> |</b>";


print "</form>\n</center>\n</body>\n</html>\n";

exit;

}else{

$errors= " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

}





