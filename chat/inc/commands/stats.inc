#!/usr/bin/perl


if ($level < 4){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";


return $errors;


exit;

}


opendir(E,"$root/online/users/");

flock(E,2);

@u = readdir(E);

closedir(E);

$c = 0;

$cop = 0;

foreach $a (@u){

if($a ne '.' && $a ne '..'){

$c++;

$a =~ s/.db//ig;

dbmopen(%USER,"$root/online/users/$a",0777);

if($USER{'level'} >= 1){

$cop++;

		}

dbmclose(%USER);

	}
}

$g = 0;

opendir(DIR, "$root/online/banned/");

foreach $y(sort(grep !/^\./, readdir DIR)){
 
$g++;

}

closedir(DIR);


$k = 0;

opendir(DIR, "$root/online/kicked/");

foreach $vv (sort(grep !/^\./, readdir DIR)){
 
$k++;
}

closedir(DIR);


open(WRPROXYTIME,"$root/online/noproxy/proxy.txt");

flock(WRPROXYTIME,2);

$pr = <WRPROXYTIME>;

close(WRPROXYTIME);

if($pr){

$prx = $time - $pr;

$prox = 30 * 60 - $prx;

$prox = &hms($prox);


}else{

$prox = "OFF";

}


$errors = " MAX_USER = 600 USERS = $c OPS = $cop BANS = $g KICKS = $k NOPROXY = $prox.";

return $errors;

exit;



sub hms {
    my $seconds = shift;
    my $minutes = int $seconds / 60;
    my $hours = int $minutes / 60;
    $minutes = $minutes % 60;
    $seconds = $seconds % 60;
    return sprintf "%02d:%02d:%02d", $hours,$minutes,$seconds;
}