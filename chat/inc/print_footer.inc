#!/usr/bin/perl

if($frames ne 'yes'){

print "<INPUT TYPE=TEXT NAME=\"msg\" SIZE=$wid MAXLENGTH=400 class=field><br>\n";

print "<INPUT TYPE=SUBMIT VALUE=\"  POST  \" class=field>\n\n";

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$DATA{'id'}\">\n";



if($menu != 1){


#print "</br>\n";



print "<SELECT class=field NAME=\"room\" onchange=\"document.forms[0].submit()\">\n";

print "<OPTION  VALUE=\"$room\" SELECTED>$room\n";

foreach $key (@rooms){

print "<OPTION VALUE=\"$key\">$key\n";

}

print "</SELECT>\n";








}else{

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$room\">";

print "<b>| <font size=\"+1\"><a href=\"$location?n=$DATA{'n'}&room=$room&id=$id&msg=/list\">$room</a></font> </b>\n";

}


print "<b>| <a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/help\"> Help </a> | <a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=\/im+1\" onClick=\"window.open('$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/im+1','w','height=500,width=645,toolbar=no,scrollbars=yes,resizable=yes')\" target=\"w\"> Images </a> | <a href=\"\/cgi-bin\/fhome\/cp.cgi\" target=_blank> Free Home</a> | <a href=\"\/cgi-bin\/fhome\/ops.cgi\" target=_blank> Sign Up </a> | <a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/quit\"> QUIT </a> | </b></form>\n</body>";
 
# <a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/images\"> 
 }else{

print "</body>\n</HTML>";


}
     return true;
