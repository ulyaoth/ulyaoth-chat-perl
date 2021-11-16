#!/usr/bin/perl

print "Content-type: text/html\n\n";

print "<HTML>\n";

print "<HEAD>\n<TITLE>$title</TITLE>\n";

print "</HEAD>\n";

print "<BODY bgcolor=\"000000\" text=\"ffffff\"><p><b>$title (Control Panel)</b><hr><p>\n"; 

if($error ne ''){

print "<center><p>$error<p></center>\n"; 

}
print "<center>\n"; 


print "<table cellpadding=1 cellspacing=0 border=\"0\">\n";

print "<form method=post action=\"cp.cgi\" target=_top>\n";

print "<tr><td colspan=2><center><b></center></b></td></tr>\n";

print "<tr><td align=right><b>Nickname </b></td><td align=left> <input size=14 maxlength=14 type=text name=\"ops\" value=\"\">\n";

print "</td></tr>\n";

print "<tr><td align=right><b>Password </b></td><td align=left> <input size=14 type=password maxlength=14 name=\"password\" value=\"\"></td></tr>\n";

print "<input type=hidden name=\"a\" value=\"login\">\n";


print "<tr><td colspan=2 align=center><input type=submit VALUE=\"Enter Control Panel\"></td></tr>\n";

print "</form></table>\n</center>\n<p>\n</body>\n</HTML>\n";


return true;
