# AdBrixRemaster-iOS
CocoaPods으로 설치를 위한, AdBrixRM.framework repo.

## x86_64, i386 include 관련 빌드 오류시
- 콘솔(터미널)에서 AdBrixRM.framework 파일 위치로 이동 후 아래 두 명령어를 입력
- lipo -remove x86_64 ./AdBrixRM.framework/AdBrixRM -o
- lipo -remove i386 ./AdBrixRM.framework/AdBrixRM -o
