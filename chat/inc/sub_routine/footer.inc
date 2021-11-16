#!/usr/bin/perl

print "<INPUT TYPE=TEXT NAME=\"msg\" class=\"Box\" SIZE=$wid MAXLENGTH=400>\n";

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$id\">";

print "<br><INPUT TYPE=SUBMIT class=\"Box2\" Value=\"POST\">\n";


if($menu != 1){

print "<SELECT NAME=\"room\" class=\"Box\" onChange=\"document.forms[0].submit()\">\n";


print "<OPTION VALUE=\"$room\" SELECTED style=\"background-color: #FFEDA3;\">$room\n";


foreach $key (@rooms){


print "<OPTION VALUE=\"$key\">$key\n";
            

}

print "</SELECT>\n";

}else{
     
print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$room\">";

print " <b> <font size=\"+1\" color=\"#3300FF\">[ <a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/list\">$room</a> ]</font></b> \n";

} 

print "</form>\n</body>";



return true;
