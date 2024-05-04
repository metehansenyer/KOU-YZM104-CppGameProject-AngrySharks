# KOÜ Yazılım Müh. Programlama 2 Dersi Dönem Projesi

Kocaeli Üniversitesi Mühendislik Fakültesi Yazılım Mühendisliği 23-24 Programlama 2 Projesi GitHub sayfası. Referans alınan oyun [Angry Sharks](https://html5games.inlogic.sk/angry-sharks/gamefiles/index.html).

# İçerik

- [Kullanılan Araçlar](https://github.com/metehansenyer/KOU-YZM104-CppGameProject-AngrySharks/tree/main?tab=readme-ov-file#kullanılan-araçlar)
- [Çalıştırma](https://github.com/metehansenyer/KOU-YZM104-CppGameProject-AngrySharks/tree/main?tab=readme-ov-file#çalıştırma)
- [Öz Değerlendirme](https://github.com/metehansenyer/KOU-YZM104-CppGameProject-AngrySharks/tree/main?tab=readme-ov-file#öz-değerlendirme)
- [İçimde Kalanlar](https://github.com/metehansenyer/KOU-YZM104-CppGameProject-AngrySharks/tree/main?tab=readme-ov-file#içimde-kalanlar)
- [Teşekkürler](https://github.com/metehansenyer/KOU-YZM104-CppGameProject-AngrySharks/tree/main?tab=readme-ov-file#teşekkürler)

## Kullanılan Araçlar

<p align="center">
<a href="https://isocpp.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a>
<a href="https://www.raylib.com/" target="_blank" rel="noreferrer"> <img src="https://github.com/raysan5/raylib/blob/master/logo/raylib_1024x1024.png?raw=true" alt="raylib" width="40" height="40"/> </a>
<a href="https://www.jetbrains.com/clion/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/clion/clion-original.svg" alt="clion" width="40" height="40"/> </a>
<a href="https://cmake.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cmake/cmake-original.svg" alt="cmake" width="40" height="40"/> </a>
<a href="https://www.adobe.com/tr/products/photoshop.html" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/photoshop/photoshop-original.svg" alt="photoshop" width="40" height="40"/> </a>
</p>

- Classları aktif olarak kullanmak istediğim için C++'ı tercih ettim.
- Görüntü işlemek için bir çok kütüphane var. Ben ihtiyaçlarım ve amacım doğrultusunda Raylib'i tercih ettim.
- Kullandığım kod editörü de CLion.
- Hem Mac hem Windows'u aynı anda kullandığım için bu projede CMake kullanmayı tercih ettim.
- Kullandığım görsellerin piksel ölçümü ve düzenlenmesi için Adobe Photoshop 24 kullandım.

| Kullandığım Araçlar Hakkında Linkler |**Link**|
|:---:|:---:|
| Compiler | [MinGW-64](https://www.mingw-w64.org/) |
| Raylib | [Get Started in raylib in 20 minutes!](https://youtu.be/RGzj-PF7D74) |
| Raylib | [Sprite Animation in Raylib](https://youtu.be/vfNn450TVxs) |
| Raylib | [ReSize Screen Problem Solution](https://stackoverflow.com/a/75513030) <br> (Kodun temeli bu ben biraz güncelledim.) |
| Raylib | [Circle and Rotated Rectangle Collision Detection](https://www.migapro.com/circle-and-rotated-rectangle-collision-detection/) <br> (Döndürülmüş bir dörtkenarın çarpışma tespiti için <br> buradaki formülizasyondan yararlanmaya çalıştım. <br> Ancak pek verimli çalışmadı belki uygulamayı <br> başaran olur diye bırakıyorum.) |

## Çalıştırma

- Öncelikle [CMake](https://cmake.org/download/)'i indirmeniz gerekli. Ya da CLion veya VSCode gibi programları ve bunların yoksa CMake eklentilerini kurmalısınız.
- [Bu linkten](https://github.com/metehansenyer/KOU-YZM104-CppGameProject-AngrySharks/archive/refs/heads/main.zip) oyunun dosyalarını indirdikten sonra kodu derleyip çalıştırmak için CMake kullanmalısınız.

| İlgili Linkler |**Link**|
|:---:|:---:|
| CLion | [Create/open CMake projects](https://www.jetbrains.com/help/clion/creating-new-project-from-scratch.html) |
| Visual Studio Code | [Import a CMake project into Visual Studio Code](https://www.pragmaticlinux.com/2021/07/import-a-cmake-project-into-visual-studio-code/) |

## Öz Değerlendirme

Bu proje sürecinde çok büyük başarılar elde ettim, sorunsuz geçti desem yalan olur. "Frame by Frame" olarak görsel akıcılık nasıl oluşturulur karakterler ekrana çizdirilirken konum ve durum tespiti nasıl yapılır. Bölüm dizaynı nasıl sağlanır. Pencere yönetimi nasıl olmalı gibi gibi bir çok konuda çokça hata yapıp doğru yolu buldum. Kodum çok iyi yazılmıştır demiyorum ancak elimden gelenin en iyisini yapmaya çalıştırdım. Benzer amaçla çalışan ancak farklı tarzda yazılmış bir çok kod parçası görebilirsiniz. Bunların bir çoğu test amaçlı böyle yazsam daha mı verimli olur diyip sonra memnun kalıp değiştirmediğim veyahut değiştirmeye üşendiğim parçalar. Kod çalışıyor sonuçta :D.

| **Kategori** | Sorun |
|:---:|:---:|
| Hareket | Oyununcunun fare hareketlerini takip etmek kolay olsa da sorun sol ve sağ rotasyonda açısal olarak karaktere şekil aldırmak. Sonuçta şu anda kod işlevsel olsa da sınırları zorlandığında veya serbest kaldığında karakterin kendi etrafında dönmesi ya da fareyle arasında mesafe kalması gibi hatalara yol açmakta. |
| Çarpışma | Yukarıda "Kullandığım Araçlar Hakkında Linkler" kısmında belirttiğim "Döndürülmüş bir dörtkenarın çarpışma tespiti..." olarak belirttiğim kısım. Sorunu kalıcı çözemesem de geçiçi olarak karakterin ağız ve burun kısmını kaplayacak bir dairenin diğer etmenlerle olan etkileşimini, balığın orijin noktasını burun kısmına taşıyarak o noktadan rotasyon almış haliyle gösterip çözdüm. Doğru değil ama işlevsel. |
| Ses | Sesler bazen düzgün çalışmıyor. Titrer gibi çıkıyor. Muhtemel Raylib paket sorunu. |
| Karakter | 3. seviye karakter boyutu çok büyük biliyorum, evet. |

## İçimde Kalanlar

- Farklı 2 düşman tipi daha eklemek istiyordum. Ancak başaramadım. "enemies.png" dosyasında onları görebilirsiniz.
- Balon balığı mekaniğini eklemiştim ancak bahsettiğim çarpışma sorunu nedeniyle düzgün çalışmıyordu. Kaldırdım.

## Teşekkürler

C ve C++ öğrenimimde katkılarından dolayı Kocaeli Üniversitesi Yazılım Mühendisliği Bölümü'den [Dr. Öğr. Üyesi İRFAN KÖSESOY](https://www.linkedin.com/in/irfankosesoy/) hocama teşekkürlerimi arz ederim.



