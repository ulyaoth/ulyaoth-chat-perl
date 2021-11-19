#!/usr/bin/perl


if($command eq '/dir' && $level < $comm_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}




print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

opendir(DIR,"$root/abuse/");

@dir = readdir(DIR);


foreach $report(sort @dir){

if($report ne '.' && $report ne '..' && $report ne 'reports'){

$report =~ s/.txt//;



print "<b> Date: ||$report||. <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/vabuse+$report\">CHECK</a>.</b><br>\n";

}}

print "<p>\n";
require "$root/inc/check_pm.inc";


require "$root/inc/print_footer.inc";

exit;