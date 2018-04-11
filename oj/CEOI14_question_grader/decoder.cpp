//category : math

int digit12[924];
 
void n2digit12(){
	int i1, i2, i3, i4, i5, i6;
	int ix = 0;
	for (i1 = 0; i1 < 12; i1++){
		for (i2 = i1 + 1; i2 < 12; i2++){
			for (i3 = i2 + 1; i3 < 12; i3++){
				for (i4 = i3 + 1; i4 < 12; i4++){
					for (i5 = i4 + 1; i5 < 12; i5++){
						for (i6 = i5 + 1; i6 < 12; i6++){
							digit12[ix++] = (1 << i1) + (1 << i2) + (1 << i3)
								+ (1 << i4) + (1 << i5) + (1 << i6);
						}
					}
				}
			}
		}
	}
}
 
int decode(int n, int q, int h) {
	static int flag = true;
	if (flag) n2digit12(),flag=false;
	int bit = 1 << (h - 1);
	return (digit12[q] & bit) != 0;	
}
