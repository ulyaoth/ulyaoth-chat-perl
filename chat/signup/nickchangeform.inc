
print "<HEAD><title>$title Chat Ops Application/ Nickname change!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='$title Chat Operator Application'\">\n";

print "<b><center>$title Chat Membership</center></b>\n";

print "<FORM METHOD=\"POST\" name=\"m\" ACTION=\"$loc\">\n";

print "<center><table width=500><tr><td><b><font size=-1>\n";

print "<u>$title Chat Membership / Nickname Change.</u>\n";

if($error){

print "<font color=\"red\"><b>$error</b></font>";

}

print "<p>";

print "<input type=hidden name=\"w\" value=\"y\">\n";

print "Input the Operator nickname:<br>\n";

print "<INPUT type=\"text\" name=\"nick\" maxlength=14 value=\"$DATA{'nick'}\"><p>\n";

print "Input the Password:<br>\n";

print "<INPUT type=\"password\" name=\"password\" maxlength=14 value=\"\"><p>\n<hr>\n";



print "Input the NEW Operator nickname:<br>\n";

print "<INPUT type=\"text\" name=\"nick2\" maxlength=14 value=\"$DATA{'nick2'}\">\n<hr><p>\n";



print "<center><INPUT TYPE=SUBMIT Value=\" SUBMIT FORM / CHANGE NICK \"></center>\n</form>";


print "</table>\n";


print "</body></html>\n";


return true;