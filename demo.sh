#!/bin/bash

case $1 in
	"0")
		echo -e ""
                (set -x;./tableau/main tests/test.txt -o tests/testCompresseT.txt -c)
		echo -e ""
		(set -x;./tableau/main tests/testCompresseT.txt -o tests/testDecompresseT.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/test.txt tests/testDecompresseT.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"1")
		echo -e ""
                (set -x;./tableau/main tests/luther.txt -o tests/lutherCompresseT.txt -c)
		echo -e ""
		(set -x;./tableau/main tests/lutherCompresseT.txt -o tests/lutherDecompresseT.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/luther.txt tests/lutherDecompresseT.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"2")
		echo -e ""
                (set -x;./tableau/main tests/image.bmp -o tests/imageCompresseT.bmp -c)
		echo -e ""
		(set -x;./tableau/main tests/imageCompresseT.bmp -o tests/imageDecompresseT.bmp -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/image.bmp tests/imageDecompresseT.bmp;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"3")
		echo -e ""
                (set -x;./tableau/main tableau/main -o tests/mainCompresseT -c)
		echo -e ""
		(set -x;./tableau/main tests/mainCompresseT -o tests/mainDecompresseT -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tableau/main tests/mainDecompresseT;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"4")
		echo -e ""
                (set -x;./tableau/main tests/son.wav -o tests/sonCompresseT.wav -c)
		echo -e ""
		(set -x;./tableau/main tests/sonCompresseT.wav -o tests/sonDecompresseT.wav -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/son.wav tests/sonDecompresseT.wav;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;

	"10")
		echo -e ""
                (set -x;./liste/main tests/test.txt -o tests/testCompresseL.txt -c)
		echo -e ""
		(set -x;./liste/main tests/testCompresseL.txt -o tests/testDecompresseL.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/test.txt tests/testDecompresseL.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"11")
		echo -e ""
                (set -x;./liste/main tests/luther.txt -o tests/lutherCompresseL.txt -c)
		echo -e ""
		(set -x;./liste/main tests/lutherCompresseL.txt -o tests/lutherDecompresseL.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/luther.txt tests/lutherDecompresseL.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"12")
		echo -e ""
                (set -x;./liste/main tests/image.bmp -o tests/imageCompresseL.bmp -c)
		echo -e ""
		(set -x;./liste/main tests/imageCompresseL.bmp -o tests/imageDecompresseL.bmp -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/image.bmp tests/imageDecompresseL.bmp;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"13")
		echo -e ""
                (set -x;./liste/main liste/main -o tests/mainCompresseL -c)
		echo -e ""
		(set -x;./liste/main tests/mainCompresseL -o tests/mainDecompresseL -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff liste/main tests/mainDecompresseL;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"14")
		echo -e ""
                (set -x;./liste/main tests/son.wav -o tests/sonCompresseL.wav -c)
		echo -e ""
		(set -x;./liste/main tests/sonCompresseL.wav -o tests/sonDecompresseL.wav -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/son.wav tests/sonDecompresseL.wav;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"20")
		echo -e ""
                (set -x;./arbre/main tests/test.txt -o tests/testCompresseA.txt -c)
		echo -e ""
		(set -x;./arbre/main tests/testCompresseA.txt -o tests/testDecompresseA.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/test.txt tests/testDecompresseA.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"21")
		echo -e ""
                (set -x;./arbre/main tests/luther.txt -o tests/lutherCompresseA.txt -c)
		echo -e ""
		(set -x;./arbre/main tests/lutherCompresseA.txt -o tests/lutherDecompresseA.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/luther.txt tests/lutherDecompresseA.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"22")
		echo -e ""
                (set -x;./arbre/main tests/image.bmp -o tests/imageCompresseA.bmp -c)
		echo -e ""
		(set -x;./arbre/main tests/imageCompresseA.bmp -o tests/imageDecompresseA.bmp -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/image.bmp tests/imageDecompresseA.bmp;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"23")
		echo -e ""
                (set -x;./arbre/main arbre/main -o tests/mainCompresseA -c)
		echo -e ""
		(set -x;./arbre/main tests/mainCompresseA -o tests/mainDecompresseA -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff arbre/main tests/mainDecompresseA;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"24")
		echo -e ""
                (set -x;./arbre/main tests/son.wav -o tests/sonCompresseA.wav -c)
		echo -e ""
		(set -x;./arbre/main tests/sonCompresseA.wav -o tests/sonDecompresseA.wav -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/son.wav tests/sonDecompresseA.wav;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"30")
		echo -e ""
                (set -x;./hash/main tests/test.txt -o tests/testCompresseH.txt -c)
		echo -e ""
		(set -x;./hash/main tests/testCompresseH.txt -o tests/testDecompresseH.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/test.txt tests/testDecompresseH.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"31")
		echo -e ""
                (set -x;./hash/main tests/luther.txt -o tests/lutherCompresseH.txt -c)
		echo -e ""
		(set -x;./hash/main tests/lutherCompresseH.txt -o tests/lutherDecompresseH.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/luther.txt tests/lutherDecompresseH.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"32")
		echo -e ""
                (set -x;./hash/main tests/image.bmp -o tests/imageCompresseH.bmp -c)
		echo -e ""
		(set -x;./hash/main tests/imageCompresseH.bmp -o tests/imageDecompresseH.bmp -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/image.bmp tests/imageDecompresseH.bmp;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"33")
		echo -e ""
                (set -x;./hash/main tableau/main -o tests/mainCompresseH -c)
		echo -e ""
		(set -x;./hash/main tests/mainCompresseH -o tests/mainDecompresseH -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff hash/main tests/mainDecompresseH;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
	"34")
		echo -e ""
                (set -x;./hash/main tests/son.wav -o tests/sonCompresseH.wav -c)
		echo -e ""
		(set -x;./hash/main tests/sonCompresseH.wav -o tests/sonDecompresseH.wav -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff tests/son.wav tests/sonDecompresseH.wav;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
esac

exit 0;
