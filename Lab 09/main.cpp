#include "Baza.cpp"
#include "Cai.cpp"
#include "Capre.cpp"
#include "Gaini.cpp"
#include "Porci.cpp"
#include "Vaci.cpp"

int main()
{
  Baza **v, *temp;
  int nrZile, i, sumNut = 0, sumGr = 0, sumIar = 0, sumMancTotal;
  double nrReumpl, nrReumpl2, mancRamasa;
  v = new Baza *[5];
  v[0] = new Vaci(10, 30, 0, 0);
  v[1] = new Gaini(100, 0, 5, 0);
  v[2] = new Cai(2, 8, 0, 0);
  v[3] = new Porci(8, 0, 4, 5);
  v[4] = new Capre(4, 4, 0, 0);
  std::cout << "Vaci: Mananca: " << v[0]->getNutPeZi() << " kg nutret, " << v[0]->getGrPeZi() << " kg graunte, " << v[0]->getIarPeZi() << " kg iarba" << std::endl;
  std::cout << "Gaini: Mananca: " << v[1]->getNutPeZi() << " kg nutret, " << v[1]->getGrPeZi() << " kg graunte, " << v[1]->getIarPeZi() << " kg iarba" << std::endl;
  std::cout << "Cai: Mananca: " << v[2]->getNutPeZi() << " kg nutret, " << v[2]->getGrPeZi() << " kg graunte, " << v[2]->getIarPeZi() << " kg iarba" << std::endl;
  std::cout << "Porci: Mananca: " << v[3]->getNutPeZi() << " kg nutret, " << v[3]->getGrPeZi() << " kg graunte, " << v[3]->getIarPeZi() << " kg iarba" << std::endl;
  std::cout << "Capre: Mananca: " << v[4]->getNutPeZi() << " kg nutret, " << v[4]->getGrPeZi() << " kg graunte, " << v[4]->getIarPeZi() << " kg iarba" << std::endl;
  for (i = 0; i < 5; i++)
  {
    sumNut += v[i]->getNutPeZi();
    sumGr += v[i]->getGrPeZi();
    sumIar += v[i]->getIarPeZi();
  }
  // sumNut + sumGr + sumIar       mancare pentru o zi
  nrZile = 2000 / (sumNut + sumGr + sumIar);
  std::cout << "Depozitul poate stoca mancare (fara a favoriza o anumita categorie) pt " << nrZile << " zile\n";
  std::cout << "Ceea ce inseamna: " << nrZile * sumNut << " kg nutret\t" << nrZile * sumGr << " kg graunte\t\t" << nrZile * sumIar << " kg iarba" << std::endl;
  nrReumpl = (double)365 / nrZile;
  if (nrReumpl > (int)nrReumpl)
  {
    nrReumpl2 = (int)nrReumpl;
    nrReumpl = (int)nrReumpl + 1;
  }
  std::cout << "Depozitul trebuie reumplut de " << nrReumpl << " ori" << std::endl;
  mancRamasa = (nrZile * sumNut - (365 - nrReumpl2 * 35 * sumNut)) * (nrReumpl - nrReumpl2);
  sumMancTotal = mancRamasa;
  std::cout << "Mancare ramasa(nutret): " << mancRamasa << std::endl;

  mancRamasa = (nrZile * sumGr - (365 - nrReumpl2 * 35 * sumGr)) * (nrReumpl - nrReumpl2);
  sumMancTotal += mancRamasa;
  std::cout << "Mancare ramasa(graunte): " << mancRamasa << std::endl;

  mancRamasa = (nrZile * sumIar - (365 - nrReumpl2 * 35 * sumIar)) * (nrReumpl - nrReumpl2);
  sumMancTotal += mancRamasa;
  std::cout << "Mancare ramasa(iarba): " << mancRamasa << std::endl;
  std::cout << "Mancare ramasa(total): " << sumMancTotal << std::endl;
  std::cout << "Se consuma " << sumNut + sumGr + sumIar << " kg de mancare pe zi" << std::endl;

  for (i = 0; i < 4; i++)
    for (int j = i + 1; j < 5; j++)
    {
      if (v[i]->getGrPeZi() + v[i]->getNutPeZi() + v[i]->getNutPeZi() < v[j]->getGrPeZi() + v[j]->getNutPeZi() + v[j]->getNutPeZi())
      {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  sumNut = sumGr = sumIar = 0;
  for (i = 0; i < 3; i++)
  {
    sumNut += v[i]->getNutPeZi();
    sumGr += v[i]->getGrPeZi();
    sumIar += v[i]->getIarPeZi();
  }
  std::cout << "Top 3 consuma in total(pe zi): " << sumNut + sumGr + sumIar << " kg" << std::endl;
}