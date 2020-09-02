<?php
    session_start();
    $j = 1;
    $qty = 1;
    require_once('dataclass.php');
    $dc = new Dataclass();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Shopping Cart</title>
    <link rel="stylesheet" href="main.css">
</head>
<body>
<form method="POST">
    
        <?php $getusers = $dc->getTable("select pro_id from cart"); 
		    $sum = $getusers->num_rows;
		?>   
    <div class="box">
        <?php
            $get = $dc->getTable("select * from products");
            while ($rw=mysqli_fetch_assoc($get))
            {
        ?>
            <div class="product">
            <h2><?= $rw['pro_name'] ?></h2>
            <h3>Rs <?= $rw['price'] ?></h3>
            <br>
            <input type="hidden" name="id" value="<?= $rw['pro_id'] ?>">
            <input type="submit" name="pro<?= $rw['pro_id'] ?>" class="form_button" value="Add">
            </div>
        <?php
            }
        ?>
    </div>
    <?php
        while($j < 6)
        {
            $x = "pro".$j;
        if(isset($_POST[$x])){
            $proid = $j;
            $check = "select pro_id from cart where pro_id = $proid";
            $getcheck = $dc->getTable($check);
            $data = $dc->getRow("select pro_id,pro_name,price from products where pro_id = $proid");
            $id = $data['pro_id'];
            $product = $data['pro_name'];
            $price = $data['price'];
            if($getcheck->num_rows == 0)
            {
                $save = "insert into cart(pro_id,pro_name,price,qty) values('$id','$product','$price','$qty')";
                if($dc->saveRecord($save))
                {
                    header("location:shop.php");
                }
                else{
                    echo "<script> alert('Error'); </script>";
                }
            }
            else{
                $update = $dc->getTable("update cart set qty = qty+1 where pro_id = $id");
                if($update)
                {
                    echo "<script> alert('Product Updated Successfully'); </script>";
                }
                else{
                    echo "<script> alert('Error in Update'); </script>";
                }
            }
        }
    $j++;
    }
    ?>
    <div class="continue"> <h1>Cart Count : <?= $sum ?></h1></div> 
    <div class="continue">
        <input type="submit" name="continue" value="Continue" class="form_button">
        <input type="submit" name="clear" value="Clear Cart" class="form_button">
    </div>
    <?php
        if(isset($_POST['continue'])){
            header('Location:cart.php');
        }

        if(isset($_POST['clear'])){
            if($dc->saveRecord("delete from cart"))
            {
                echo "<script> alert('Cart Is Empty Now'); </script>";
                header("location:shop.php");
            }
            else{
                echo "<script> alert('Error in Deletion'); </script>";
            }
        }
    ?>
</form>
</body>
</html>