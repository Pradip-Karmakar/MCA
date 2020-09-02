<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Assignment 1 XT14</title>
    <link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
    <div class="box">
    <?php
        function number($value,$key)
        {
            echo "<br>The $key called $value ";
        }
            $arr = array("1"=>"one","2" => "two","3" => "three","4" => "four","5" => "five");
            $temp = "hello";
            $temparr = array("temp" => "Morning", "temp2" => "Night", "temp3" => "Evening");

            echo "<table border = '1'>";
            echo "<tr><td>Each : </td><td>";
            print_r (each($arr));

            echo "</td></tr> <br> <tr><td>Current : </td><td>" . current($arr) . "</td></tr>";

            echo "<br> <tr><td> Reset : </td><td>" . reset($arr). "</td></tr>";

            echo "<br> <tr><td> End : </td><td>" . end($arr). "</td></tr>";

            echo "<br> <tr><td> POS : </td><td>" . pos($arr). "</td></tr>";

            echo "<br> <tr><td> Prev : </td><td>" . prev($arr) . "<br><tr><td>Array_Walk : </td><td>";

            echo "</td></tr> <br> <tr><td> Array_walk Return : </td><td>" . array_walk($temparr,"number"). "</td></tr>";

            echo "<br> <tr><td> Count : </td><td>" . count($arr). "</td></tr>";

            echo "<br> <tr><td>Sizeof : </td><td>" . sizeof($arr) . "</td></tr> <br> <tr><td>Array_count_values : </td><td>";
            
            print_r  (array_count_values($arr));
            echo "</td></tr>";

            extract($temparr);
            echo "<br> <tr><td>Extract : </td><td>" . $temp . "</td></tr></table>";
        ?>
    </div>
</body>
</html>
