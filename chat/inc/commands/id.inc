#!/usr/bin/perl



if ($command eq '/id' && $level >= 4){ 



@id = split(/\s+/, $DATA{'msg'});





unless(@id[1]){



$errors = " Syntax: /id [nick].";



return $errors;



}





if(!-e "$root/online/users/@id[1]"){



$errors = " Error, user <b>@id[1]</b> not found.";



return $errors;



}





dbmopen(%ID,"$root/online/users/@id[1]",0777);




$opid = $ID{'opsid'};



$nip = $ID{'ip'};



$userlevel = $ID{'level'};



$used_nickss = $ID{'usednicks'};



$fip = $ID{'fullip'};



$usera = $ID{'user_agent'};



$host = $ID{'host_name'};



$time = time();



$tim = $time - $ID{'online'};


open(M,"$root/time/@id[1].dat");

flock(M,1);

$n = <M>;

$i = $n + $tim;

$full_monthly_time = &hms($i);

close(M);


$onlinet = &hms($tim);


sub hms {
    my $seconds = shift;
    my $minutes = int $seconds / 60;
    my $hours = int $minutes / 60;
    $minutes = $minutes % 60;
    $seconds = $seconds % 60;
    return sprintf "%02d:%02d:%02d", $hours,$minutes,$seconds;
}


$ref = $ID{'referer'};



$ff = $ID{'frames'};



if($ff ne 'yes'){



$ff = "none";



}



$proxy = $ID{'proxy'};



$rnick = $ID{'realnick'};



$trace = $ID{'realip'};



$usednicks = $ID{'usednicks'};



dbmclose(%ID);









if ($level < $userlevel){





$errors = " @id[1] is actually $rnick ip=$nip id=$opid rank=$userlevel. ";



return $errors;





}elsif($level >= $userlevel && $level < $comm_rank){         



$errors = " @id[1] is actually $rnick ip=$nip id=$opid rank=$userlevel.";



return $errors;





}elsif($level >= $userlevel && $level >= $comm_rank){







$errors = " @id[1] is actually $rnick ip=$nip id=$opid rank=$userlevel user_agent=$usera fullip=$fip host=$host proxy=$proxy trace=$trace frames=$ff onlinetime=$onlinet onlinetime($amonth)=$full_monthly_time referer=$ref usednicks=$used_nickss.";



return $errors;



}

}



 





if ($command eq '/id' && $level >= 1 && $level < 4){

                

@id = split(/ /, $DATA{'msg'});



if(@id[1] eq $DATA{'n'}){



dbmopen(%ID,"$root/online/users/@id[1]",0777);





$opid = $ID{'opsid'};



$nip = $ID{'ip'};



$userlevel = $ID{'level'};



$fip = $ID{'level'};



$usera = $ID{'user_agent'};



$host = $ID{'host_name'};



$ref = $ID{'referer'};



$rnick = $ID{'realnick'};



dbmclose(%ID);







$errors = " $DATA{'n'} is actually $rnick ip=$nip id=$opid rank=$level.";



return $errors;



}else{





        $errors = "  Error, Operators lower than level 4 can only id themselves.";

        

 return $errors;



}}





if ($command eq '/id' && $level < 1){

                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";



        }

        