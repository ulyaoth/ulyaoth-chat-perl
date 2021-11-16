#!/usr/bin/perl

if($level < $admin_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}

@b = split(/\s+/, $DATA{'msg'});


if(@b[1] eq "reset"){

$w = 0;

opendir(BOOT,"$root/time/");

@dirlists = readdir(BOOT);

closedir(BOOT);

foreach $i(@dirlists){

if($i ne '.' && $i ne '..'){

$w++;

unlink ("$root/time/$i");

	}
}

$errors = " Time system directory has been reseted. Total <b>$w</b> file(s) erased. Running month ($amonth).";
        
return $errors;

exit;

}







if(!@b[1]){

$errors = " Syntax: /chk [nick], /chk reset.";
        
return $errors;

exit;

}


if(!-e "$root/ops/ops/@b[1]"){

$errors = " Error, operator <b>@b[1]</b> not found.";
        
return $errors;   

exit;

}


open(M,"$root/time/@b[1].dat");

flock(M,1);

$n = <M>;

close(M);

if(-e "$root/online/users/@b[1]"){

dbmopen(%D,"$root/online/users/@b[1]",0777);

$e = $time - $D{'online'};

dbmclose(%D);

}

$qq = &hms($n);

if($e){

$uh = $e + $n;

$tot = &hms($uh);

$ss = &hms($e);

$errors = " Account <b>@b[1]</b> time($amonth)=$qq. Currently online, running time=$ss. Total time=$tot.";

return $errors;

exit;

}else{


$errors = " Account <b>@b[1]</b> time($amonth)=$qq. Currently offline.";

return $errors;

exit;


}


sub hms {

    my $seconds = shift;
    my $minutes = int $seconds / 60;
    my $hours = int $minutes / 60;
    $minutes = $minutes % 60;
    $seconds = $seconds % 60;
    return sprintf "%02d:%02d:%02d", $hours,$minutes,$seconds;

}















