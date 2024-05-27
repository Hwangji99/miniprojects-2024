using MahApps.Metro.Controls;
using MahApps.Metro.Controls.Dialogs;
using MQTTnet.Client;
using System.Threading.Tasks;
using System.Windows;

namespace SmartHomeMonitoringApp.Logics
{
    public class Commons
    {
        public static string BROKERHOST { get; internal set; } = "192.168.5.2"; // Window MQTT Broker Mosquitto IP
        public static string MQTTTOPIC { get; internal set; } = "pknu/data/"; // 대소문자 구분, 마지막 /도 중요!!
        public static string DBCONNSTRING { get; internal set; } = "Data Source=127.0.0.1;Initial Catalog=EMS;Persist Security Info=True;User ID=sa;Encrypt=False;" +
                                                                    "Password=mssql_p@ss";
        public static IMqttClient MQTT_CLIENT { get; set; } // 전체 프로젝트에서 다 사용할 공용 Mqtt 클라이언트
    }
}
