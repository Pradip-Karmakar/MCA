<?php

include 'dataClass.php';
$dc = new Dataclass();

$country = $dc->getTable("select * from countries");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>XT2</title>
    <style>
        body{
            margin: 0;
            background-color:aqua; 
        }
        .box{
            text-align: center;
            margin: 10% 0 0 0;
        }
        .form_select{
            width: 28%;
            height: 55px;
            border-radius: 5px;
            border: 2px solid aquamarine;
            padding: 10px;
            margin-top: 10px;
            font-size: medium;
        }

        .form_button{
            width: 35%;
            height: 45px;
            border-radius: 5px;
            border: 0px;
            background-color: red;
            margin: 10px 0 20px 0;
            font-weight: bold;
        }

        .form_button:hover{
            cursor: pointer;
            background-color: greenyellow;
        }
        
    </style>
</head>
<body>
    <div class="box">
        <form method="POST">
            <div>
                <select name="country" id="country" class="form_select">
                    <?php
                        while($row=mysqli_fetch_assoc($country))
                        {
                    ?>
                            <option value="<?= $row['id'] ?>"> <?= $row['name'] ?> </option>
                    <?php
                        }
                    ?>
                </select>
                <select name="state" id="state" class="form_select">
                    <option value="no">-------</option>
                </select>
                <select name="city" id="city" class="form_select">
                <option value="no">-------</option>
                </select>
            </div>
            <div id="btn">
                <input type="submit" name="submit" class="form_button" id="submit">
            </div>
        </form>
    </div>
    <?php
    if(isset($_POST['submit']))
    {
        $country = $dc->getRow("select name from countries where id = $_POST[country]");
        $state = $dc->getRow("select name from states where state_id = $_POST[state]");
        $city = $dc->getRow("select name from cities where city_id = $_POST[city]");
    ?>
    <div style="text-align: center;">
        <h2> <?= "You have selected ". $city['name'] ." City of " . $state['name'] . " State of " . $country['name'] ?> </h2>
    </div>
    <?php
    }
    ?>
    <script type="text/javascript" src="jquery-min.js"></script>
    <script>
    $(document).ready(function() {
        $("#btn").hide();

        $("#country").on("change",function() {
         
            var val = $(this).val();
            $.ajax({
                    type:"POST",
                    url:"getState.php",
                    data:{ country : val },
                    success:function(response){
                    $("#state").html(response);
                    
                    }
                });
        });

        $("#state").on("change",function() {
            var val = $(this).val();
            $.ajax({
                    type:"POST",
                    url:"getCity.php",
                    data:{ state : val },
                    success:function(response){
                    $("#city").html(response);
                    }
                });
        });

        $("#city").on("change",function(){
            $("#btn").show();
        });

    });
    </script>
</body>
</html>
