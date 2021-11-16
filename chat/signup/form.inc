
print "<HEAD><title>$title Chat Ops Application!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='$title Chat Operator Application'\">\n";

print "<b><center>$title Chat Membership</center></b>\n";

print "<FORM METHOD=\"POST\" name=\"m\" ACTION=\"$loc\">\n";

print "<center><table width=500><tr><td><b><font size=-1>\n";

print "<u>FREE TRIAL OPERATOR APPLICATION.</u>\n";

if($error){

print "<font color=\"red\"><b>$error</b></font>";

}

print "<p>";

print "<input type=hidden name=\"w\" value=\"y\">\n";

print "Input the Operator nickname:<br>\n";

print "<INPUT type=\"text\" name=\"opsnickname\" maxlength=14 value=\"$DATA{'opsnickname'}\"><p>\n";

print "Input the Password.(4-12 characters, only alphanumerical characters are allowed):<br>\n";

print "<INPUT type=\"password\" name=\"password\" maxlength=14 value=\"\"><p>\n";

print "Input the Same Password again (verification):<br>\n";

print "<INPUT type=\"password\" name=\"2password\" maxlength=14 value=\"\"><p>\n";



print "Select Length:<br>\n";

print "<select name=\"length\" size=\"1\">\n";
print "<option value=\"1\">1 Month (Trial Ops - 0 US \$)</option>\n";
print "<option value=\"3\">3 Months (15 US \$)</option>\n";
print "<option value=\"6\">6 Months (30 US \$)</option>\n";
 print "<option value=\"9\">9 Months (45 US \$)</option>\n";
 print "<option value=\"12\">12 Months (55 US \$)</option>\n";
 print "<option value=\"24\">24 Months (100 US \$)</option>\n";
  print "</select><p>\n";

print "Input the E-mail Address:<br>\n";

print "<INPUT type=\"text\" name=\"email\" maxlength=700 value=\"$DATA{'email'}\"><p>\n";

print "Input the Name:<br>\n";

print "<INPUT type=\"text\" name=\"nameofowner\" maxlength=30 value=\"$DATA{'nameofowner'}\"><p>\n";

print "Input the Surname (optional):<br>\n";

print "<INPUT type=\"text\" name=\"surnameofowner\" maxlength=30 value=\"$DATA{'surnameofowner'}\"><p>\n";

print "Gender (optional):<br>\n";

print "<input type=radio name=\"gender\" checked value=\"male\"> Male";

print "<input type=radio name=\"gender\" value=\"female\"> Female<p>\n";

print "Street Address (optional):<br>\n";

print "<INPUT type=\"text\" name=\"street\" maxlength=80 value=\"$DATA{'street'}\"><p>\n";

print "Zip/Postal Code (optional):<br>\n";

print "<INPUT type=\"text\" name=\"zipcode\" size=9 maxlength=9 value=\"$DATA{'zipcode'}\"><p>\n";

print "Country (optional):<br>\n";

print "<INPUT type=\"text\" name=\"country\"  maxlength=40 value=\"$DATA{'country'}\"><p>\n";

print "Phone Number, including country and area code (optional):<br>\n";

print "<INPUT type=\"text\" name=\"phone\"  maxlength=40 value=\"$DATA{'phone'}\"><p>\n";


print "<center><INPUT TYPE=SUBMIT Value=\" SUBMIT FORM \"></center>\n";

print "</table>\n";


print "</body></html>\n";


return true;