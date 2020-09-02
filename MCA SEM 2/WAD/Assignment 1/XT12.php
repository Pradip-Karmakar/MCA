<?php
    $cards = array( array("C_A","C_K","C_Q","C_J","C_10","C_9","C_8","C_7","C_6","C_5","C_4","C_3","C_2"),
                    array("H_A","H_K","H_Q","H_J","H_10","H_9","H_8","H_7","H_6","H_5","H_4","H_3","H_2"),
                    array("D_A","D_K","D_Q","D_J","D_10","D_9","D_8","D_7","D_6","D_5","D_4","D_3","D_2"),
                    array("S_A","S_K","S_Q","S_J","S_10","S_9","S_8","S_7","S_6","S_5","S_4","S_3","S_2")
    );
    echo "Decending Order";
    echo "<table border='1px'>";
    for( $i = 0; $i < 4; $i++ )
    {
        echo "<tr>";
        for( $j = 0; $j < 13; $j++ )
        {
            echo "<td>";
            echo $cards[$i][$j];
            echo "</td>";
        }
        echo "</tr>";
    }
    echo "</table> <br>";

    echo "Accending Order";
    echo "<table border='1px'>";
    for( $i = 3; $i >= 0; $i-- )
    {
        echo "<tr>";
        for( $j = 12; $j >= 0; $j-- )
        {
            echo "<td>";
            echo $cards[$i][$j];
            echo "</td>";
        }
        echo "</tr>";
    }
    echo "</table> <br>";

    echo "After Shuffle";
    echo "<table border='1px'>";
    shuffle($cards);
    for( $i = 0; $i < 4; $i++ )
    { 
        echo "<tr>";
       for( $j = 0; $j < 13; $j++ )
       {
            shuffle($cards);
            shuffle($cards[0]);
            while( $cards[$i][$j] == "" )
            {
                shuffle($cards);
                shuffle($cards[0]);
            }
            echo "<td>";
            echo $cards[$i][$j];
            echo "</td>";
            $cards[$i][$j] = "";
       }
       echo "</tr>";
    }
    echo "</table>";
?>