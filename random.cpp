#include <iostream>
// #include <cstdlib>
#include  <stdlib.h>
using namespace std;

int main(){

	int i;
	int random;

	i = 1;
	// Providing a seed value
	srand((unsigned) time(NULL));
	// Loop to get 5 random numbers
	while (i <= 500)
	{

		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		if (!(i % 5))
		random = 900 + (rand() % 101);
		else if (!(i % 3))
		random = 800 + (rand() % 105);
		else if (!(i % 4))
		random = 700 + (rand() % 106);
		else if (!(i % 2))
		random = 500 + (rand() % 107);
		else
		random = 400 + (rand() % 109);
	printf("%d\n",random);
		// cout<<random<<endl;
		i++;
	}
	return 0;
}

481
521
812
738
937
887
447
733
816
913
408
810
448
561
991
796
475
817
404
942
880
554
481
887
937
555
868
798
491
935
447
790
830
549
923
879
490
560
895
989
435
839
419
773
965
533
433
890
451
998
862
770
449
809
969
756
804
561
430
959
456
552
858
781
935
866
504
751
808
995
436
864
408
505
902
803
483
833
507
903
838
564
494
837
949
515
864
768
470
953
473
716
848
537
944
883
479
525
816
999
467
813
421
778
951
593
419
828
500
998
854
759
469
856
955
733
871
589
402
992
447
595
835
755
973
828
474
746
820
988
502
851
502
544
919
704
437
901
455
967
840
600
471
851
955
531
873
738
417
921
417
805
858
531
931
873
486
517
825
930
448
803
497
782
965
601
413
848
431
995
896
723
499
860
957
719
885
597
481
936
431
539
839
725
934
804
507
705
809
965
481
871
475
548
923
769
468
843
460
923
904
513
507
896
913
533
805
790
403
947
474
754
858
532
968
875
464
554
887
966
466
858
480
796
995
505
459
836
489
995
856
703
417
864
911
718
902
573
450
905
414
585
870
760
963
892
494
774
811
991
495
824
447
578
961
776
408
886
427
1000
904
548
489
835
918
592
901
726
424
958
447
749
808
530
995
899
493
531
837
977
433
903
500
759
960
523
431
800
416
962
819
799
457
886
903
753
884
510
442
933
428
561
899
768
941
890
432
729
804
936
468
876
490
601
924
756
493
845
414
921
828
602
496
833
900
605
896
768
442
940
497
731
894
551
957
803
413
575
901
918
457
877
416
727
923
585
419
875
493
984
892
756
404
830
961
755
884
561
430
993
451
521
836
802
922
870
469
702
889
996
501
818
436
598
912
723
407
851
434
966
828
571
463
899
991
580
815
738
417
973
464
721
887
502
991
904
495
601
890
997
426
805
403
754
999
579
421
838
409
966
812
793
507
903
900
771
875
528
467
938
465
587
869
753
975
878
502
752
889
917
423
824
506
504
923
725
478
894
413
983
845
533
474
817
998
546
900
707
436
981
477
805
881
548
924
889
506
572
825
927
452
808
401
706
909
572
488
897
498
932
896
703
465
808
911
791
864
558
404
931
461
535
846
775
967
810
414
725
823
949
462
831
431
532
959
737
497
888
427
967
