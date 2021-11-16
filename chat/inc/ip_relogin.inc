#!/usr/bin/perl

print "<HTML>\";


print "<HEAD><TITLE>$title</TITLE></HEAD>\n";

print "<BODY $onload>\n"; 

print "<b>$entrytitle - Please login</b><hr>\n"; 


print "<p>*** IP relogin ($ENV{'REMOTE_ADDR'}). Please wait...<p>\n"; 

print "<center>\n"; 

print "<b>Password is Optional for Non-Ops.</b><br><p>\n";

print "<table cellpadding=1 cellspacing=0 border=\"2\">\n";

print "<form method=post action=\"$location#b\" target=_top>\n";

print "<tr><td colspan=2><center><b>Chat Entry</center></b></td></tr>\n";

print "<tr><td align=right><b>Nickname </b></td><td align=left> <input size=14 maxlength=14 type=text name=\"n\" value=\"\">\n";

print "</td></tr>\n";

print "<tr><td align=right><b>Password </b></td><td align=left> <input size=14 type=password maxlength=14 name=\"pass\" value=\"\"></td></tr>\n";

print "<input type=hidden name=\"w\" value=\"y\">";

print "<input type=hidden name=\"id\" value=\"\">";

print "<tr><td align=right><b>Room </b></td>\n";

print "<td align=left><select name=\"room\">\n";


print "<option  value=\"$firstroom\" SELECTED >$firstroom\n";

foreach $key (@rooms){
                print "<OPTION VALUE=\"$key\">$key\n";
        }

print "</select>\n";

print "</td></tr>\n";

print "<tr><td align=right><b>Frames </b></td>\n";

print "<td align=left>\n";

print "<input type=radio name=\"frames\" value=\"yes\"> YES\n";

print "<input type=radio name=\"frames\" checked value=\"\"> NONE\n";

print "</td></tr>\n";

print "<tr><td colspan=2 align=center><input type=submit VALUE=\"Enter Chat\"></td></tr>\n";

print "</form></table>\n</center>\n<p>\n</body>\n</HTML>\n";


return true;
