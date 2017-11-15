#include "halcon2QT.h"

using namespace HalconCpp;

QImage Hobject2QImage(HObject hobject)
{
	QImage image;
	HTuple ptrR, ptrG, ptrB;
	HTuple  hv_Pointer, hv_Type, hv_Width, hv_Height, nchannels;
	uchar *data;
	QVector<QRgb> colorTable;
	if (hobject.IsInitialized()==1)
	{
		ConvertImageType(hobject, &hobject, "byte");
		GetImageSize(hobject, &hv_Width, &hv_Height);
		CountChannels(hobject, &nchannels);
		if (3 == nchannels)
		{
			GetImagePointer3(hobject, &ptrR, &ptrG, &ptrB, NULL, NULL, NULL);
			image = QImage(hv_Width.I(), hv_Height.I(), QImage::Format_RGB888);
			for (int i = 0; i<hv_Height.I(); i++)
			{
				data = image.scanLine(i);
				for (int j = 0; j<hv_Width.I(); j++)
				{
					data[j * 3] = ptrR[i*hv_Width + j].I();
					data[j * 3 + 1] = ptrG[i*hv_Width + j].I();
					data[j * 3 + 2] = ptrB[i*hv_Width + j].I();
				}
			}
		}
		else if (1 == nchannels)
		{

			for (int i = 0; i<256; i++)
			{
				colorTable.append(qRgb(i, i, i));
			}
			GetImagePointer1(hobject, &hv_Pointer, NULL, NULL, NULL);
			image = QImage(hv_Width.I(), hv_Height.I(), QImage::Format_Indexed8);
			BYTE *p = (BYTE *)hv_Pointer[0].I();
			for (int i = 0; i<hv_Height.I(); i++)
			{
				data = image.scanLine(i);
				for (int j = 0; j<hv_Width.I(); j++)
				{
					data[j] = p[i*hv_Width.I() + j];
				}
			}
			image.setColorTable(colorTable);
		}
	}
	return image;
}
