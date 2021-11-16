
print "<HEAD><title>$title Chat Ops Application/ RENEWAL!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='$title Chat Operator Application'\">\n";

print "<b><center>$title Chat Membership</center></b>\n";

print "<FORM METHOD=\"POST\" name=\"m\" ACTION=\"$loc\">\n";

print "<center><table width=500><tr><td><b><font size=-1>\n";

print "<u>$title Chat Membership Renewal.</u>\n";

if($error){

print "<font color=\"red\"><b>$error</b></font>";

}

print "<p>";

print "<input type=hidden name=\"w\" value=\"y\">\n";

print "Input the Operator nickname:<br>\n";

print "<INPUT type=\"text\" name=\"nick\" maxlength=14 value=\"$DATA{'nick'}\"><p>\n";

print "Input the Password:<br>\n";

print "<INPUT type=\"password\" name=\"password\" maxlength=14 value=\"\"><p>\n";


print "Select Length:<br>\n";

print "<select name=\"length\" size=\"1\">\n";
print "<option value=\"3\">3 Months (15 US \$)</option>\n";
print "<option value=\"6\">6 Months (30 US \$)</option>\n";
 print "<option value=\"9\">9 Months (45 US \$)</option>\n";
 print "<option value=\"12\">12 Months (55 US \$)</option>\n";
 print "<option value=\"24\">24 Months (100 US \$)</option>\n";
  print "</select><p>\n";

print "<center><INPUT TYPE=SUBMIT Value=\" SUBMIT FORM / RENEW ACCOUNT \"></center>\n</form>";


print "</table>\n";


print "</body></html>\n";


return true;