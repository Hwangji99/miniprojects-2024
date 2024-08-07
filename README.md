# 미니 프로젝트 2024
IoT 개발자 미니 프로젝트 리포지토리

## 1일차(2024-05-14)
- 조별 자리배치
- IoT 프로젝트 개요

    ![IoT프로젝트](https://raw.githubusercontent.com/Hwangji99/miniprojects-2024/main/images/mp001.png)

    1. IoT 기기 구성 - 아두이노, 라즈베리파이 등 IoT장비들과 연결
    2. 서버 구성 - IoT 기기와 통신, DB구성, 데이터 수집 앱 개발
    3. 모니터링 구성 - 실시간 모니터링/제어 앱, 전체 연결

- 조별 미니프로젝트
    - 5월 28일 (40시간)
    - 구체적으로 어떤 디바이스 구성, 데이터 수집, 모니터링 계획
    - 8월 말 정도에 끝나는 프로젝트 일정 계획
    - 요구사항 리스트, 기능명세, UI/UX에 대한 디자인, DB설계 문서 하나로 통합
    - 5월 28일 오후 각 조별로 파워포인트/프레젠테이션 10분 발표
    - 요구사항 리스트 문서전달
    - 기능 명세 문서
    - DB설계 ERD 또는 SSMS 물리적 DB설계
    - UI/UX 디자인 16일(목) 내용 전달

## 2일차(2024-05-16)
- 미니프로젝트
    - 프로젝트 문서
    - Notion 팀 프로젝트 템플릿 활용
    - UI/UX 디자인 툴 설명
        - https://ovenapp.io/ 카카오
        - https://figma.com/ 피그마
        - https://app.moquos.com/ 목업디자인 사이트
    - 라즈베리파이(RP) 리셋팅, 네트워크 설정, VNC(OS를 UI로 작업)
    - 프레젠테이션
        - https://www.miricanvas.com/ko 미리캔버스 활용 추천
    - 피그마 단축키
       1. V - 선택도구
       2. A - 직선도구
       3. T - 텍스트도구
       4. Space + Drag - 마우스 커서에 따라 원하는 영역으로 이동
       5. Ctrl + R - 레이어 이름 변경
       6. Ctrl + G - 객체 그룹화
       7. Ctrl + Shift + G - 객체 그룹 해제
       8. Ctrl + D - 선택한 객체 복사
       9. Ctrl + [ - 선택한 객체 뒤로 보내기
       10. Ctrl + ] - 선택한 객체 앞으로 보내기

- 스마트홈 연동 클래스 미니프로젝트
    1. 요구사항 정의, 기능 명세, 일정 정리
    2. UI/UX 디자인
        - RPi는 디자인 없음(콘솔)
        - 데이터 수신앱
        - 모니터링 앱
    3. DB설계
    4. RPi 셋팅(Network)
    5. RPi GPIO에 IoT 디바이스 연결(카메라, HDT(온습도센서), RGB LED, ...)
    6. RPi 데이터 전송하는 파이썬 프로그래밍
    7. PC(Server) 데이터 수신 C# 프로그래밍
    8. 모니터링 앱 개발(수신 및 송신)

## 3일차(2024-05-17)
- 미니 프로젝트
    - 실무 프로젝트 문서
    - Jira 사용법
    - 조별로 진행

- 라즈베리파이 셋팅
    1. RPi 기본 구성 - RPi + MicroSD + Power
    2. RPi 기본 세팅
        - [x] 최신 업그레이드
        - [x] 한글화
        - [x] 키보드 변경
        - [x] 화면 사이즈 변경 (RealVNC사용)
        - [x] Pi Apps 앱설치 도우미 앱
        - [x] Github Desktop, VS Code
        - [x] 네트워크 확인
        - [ ] RealVNC Server 자동실행 설정

- 스마트홈 연동 클래스 미니 프로젝트
    - RPi 셋팅 및 진행

## 4일차(2024-05-20)
- 라즈베리파이 IoT장비 설치
    - [x] 라즈베리파이 카메라
    - [x] GPIO HAT
    - [x] 브레드보드와 연결
    - [ ] DHT11 센서
    - [x] RGB LED 모듈
        - V - 5V 연결
        - R - GPI04 연결
        - B - GPI05 연결
        - G - GPI06 연결
    - [ ] 서보모터

## 5일차(2024-05-21)
- 라즈베리파이 IoT장비 설치
    - [x] DHT11(온습도) 센서
        - GND - GND 8개 중 아무데나 연결
        - VCC - 5V 연결
        - S - GPIO18 연결

- 라즈베리파이 마우스 속도 높이기
    - sudo nano /boot/firmware/cmdline.txt
    - 끝에 usbhid.mousepsuoll=0
    - reboot

- 라즈베리파이 무선랜 연결
    - nano /etc/wpa_supplicant/wpa_supplicant.conf
    - nano /etc/rc.loaclsudi
    ```shell
    sudo iw reg set KR
    sudo iwconfig wlan0 power off # wifi 연결이 끊기지 않음
    ```
    
    - reboot

## 6일차(2024-05-22)
- 개인 공유기 설치
- RealVNC
    1. 라즈베리 파이에서 RealVNC Server 실행 또는 ifconfig를 통해 라즈베리 파이 IP주소 확인
    2. 

## 7일차(2024-05-23)
- 스마트홈 연동 클래스 미니프로젝트
    - 온습도 센서, RGB LED
    - RPi <--> Windows 통신(MQTT)
    - WPF 모니터링 앱

- IoT 기기간 통신방법
    - Modbus - 시리얼 통신으로 데이터 전송(완전 구식)
    - OPC UA - Modbus 통신의 불편한 점을 개선(아주 복잡)
    - **MQTT** - 가장 편리함, AWS IoT나 Azure IoT 클라우드 산업계표준으로 사용(OPC UA를 개선)

- MQTT 통신에 필요한 것들
    - [x] Mosquitto Broker 설치
        - mosquitto.conf > notepad++로 열기 > listner 1888 0.0.0.0,  allow_anonymous true
        - 방화벽 인바운드 열기
    - [x] RPi : paho-mqtt 패키지 설치, 송신(publisher)
    - [ ] Win/C# : MQTT.NET Nuget 패키지 설치, 수신(subscriber)
        - M2Mqtt : 가볍게 쓸 수 있음, 업데이트가 안됨
        - MQTTNet : MS에서 개발, 무겁다, 최신까지 업데이트 잘 됨

## 8일차(2024-05-24)
- MQTT화 통신
    - 라즈베리파이에서 얻은 온습도 정보를 MQTT를 통해 컴퓨터로 가져오기

## 9일차(2024-05-27)
- 스마트홈 연동 클래스 미니프로젝트
    - [x] WPF MQTT 데이터 DB로 저장
    - [x] MQTT 데이터 실시간 모니터링 - 온도
    - [ ] MQTT로 RPi 제어(LED제어)
    - [ ] WPF MQTT 데이터 히스토리 확인

## 10일차(2024-05-28)
- 스마트홈 연동 클래스 미니프로젝트 마무리
    - [x] WPF MQTT 데이터 DB로 저장
    - [x] MQTT 데이터 실시간 모니터링 - 습도
    - [x] MQTT로 RPi 제어(LED제어)
    - [x] WPF MQTT 데이터 히스토리 확인
        - LiveChart2는 차후에 다시, 현재는 OxyPlot 차트 대체

    - 실행결과

        ![스마트홈1](https://raw.githubusercontent.com/Hwangji99/miniprojects-2024/main/images/mp002.png)

        ![스마트홈2](https://raw.githubusercontent.com/Hwangji99/miniprojects-2024/main/images/mp003.png)

        ![스마트홈3](https://raw.githubusercontent.com/Hwangji99/miniprojects-2024/main/images/mp004.png)


- 조별 미니프로젝트 발표
