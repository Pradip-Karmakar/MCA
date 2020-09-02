<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT11</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
      <form method="POST">
        <div>
          <select name = "cityA">
              <option value = 0>Navsari</option>
              <option value = 1>Surat</option>
              <option value = 2>Ahmedabad</option>
              <option value = 3>Kutchh</option>
              <option value = 4>Mumbai</option>
            </select>
          
            <select name = "cityB">
              <option value = 0>Navsari</option>
              <option value = 1>Surat</option>
              <option value = 2>Ahmedabada</option>
              <option value = 3>Kutchh</option>
              <option value = 4>Mumbai</option>
            </select>
          </div>
          <div>
              <input type="submit" value="Submit" name="submit" class="submit">
          </div>
      </form>
      <?php
        if(isset($_POST['submit'])) {
          $cityA = $_POST['cityA'];
          $cityB = $_POST['cityB'];
          $city = array (
            "Navsari",
            "Surat",
            "Ahmedabad",
            "Kutchh",
            "Mumbai"
          );

          $distance = array (
            array (0, 40, 398, 733, 426),
            array (40, 0, 358, 693, 466),
            array (398, 358, 0, 362, 850),
            array (733, 693, 362, 0, 1162),
            array (426, 466, 850, 1162, 0)
          );

          $result = $distance[$cityA][$cityB];
          print "<h3>The distance between ";
          print "$city[$cityA] to $city[$cityB]";
          print " is $result Kms.</h3>";
        }
        ?>
	</div>
</body>
</html>