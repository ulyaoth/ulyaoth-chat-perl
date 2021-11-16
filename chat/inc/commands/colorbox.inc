#!/usr/bin/perl

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";


print <<"(END HTML FOOTER)";

<center>
<script language="JavaScript">

clr=new Array('00','20','40','60','80','a0','c0','ff');
for (i=0;i<8;i++) { 
document.write("<table border=1 cellpadding=8>");
for (j=0;j<8;j++) {
document.write("<tr>");
for (k=0;k<8;k++) {
document.write('<td bgcolor="#'+clr[i]+clr[j]+clr[k]+'">');
document.write('<tt><font color="#'+clr[7-i]+clr[7-j]+clr[7-k]+'"><a style="text-decoration: none"  href="$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/color+'+clr[i]+clr[j]+clr[k]+'"> ');
document.write(clr[i]+clr[j]+clr[k]+' </a></font></tt></td>'); }
document.write("</tr>"); }
document.write("</table><br>"); }
// end -->
</script>
</center>
<p>
<p><b>To select desired color just click on it.</b>

<p>
(END HTML FOOTER)

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;


