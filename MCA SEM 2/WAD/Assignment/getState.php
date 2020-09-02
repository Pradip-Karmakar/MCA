<?php 
include 'dataClass.php';
    $dc = new Dataclass();
    if (isset($_POST['country'])) {
    $country = $_POST['country'];

    $cmpd = $dc->getTable("select * from states where country_id = ".$country);
    $res = "<option value='0'> Select State </option>";
    while ($cmprw = mysqli_fetch_assoc($cmpd)) {
        $res .= "<option value='".$cmprw['state_id']."'>".$cmprw['name']."</option>";
    }

    echo $res;

    }

 ?>