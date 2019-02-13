#ifndef BNO055_HPP
#define BNO055_HPP

#include "Vector3.hpp"

const uint8_t BNO055_ADDRESS_A = 0x28;
const uint8_t BNO055_ADDRESS_B = 0x29;
const uint8_t BNO055_CHIP_ID = 0xA0;

class BNO055
{
    enum RegisterAddr {
      /* Page id register definition */
      PAGE_ID_ADDR                                     = 0X07,

      /* PAGE0 REGISTER DEFINITION START*/
      CHIP_ID_ADDR                                     = 0x00,
      ACCEL_REV_ID_ADDR                                = 0x01,
      MAG_REV_ID_ADDR                                  = 0x02,
      GYRO_REV_ID_ADDR                                 = 0x03,
      SW_REV_ID_LSB_ADDR                               = 0x04,
      SW_REV_ID_MSB_ADDR                               = 0x05,
      BL_REV_ID_ADDR                                   = 0X06,

      /* Accel data register */
      ACCEL_DATA_X_LSB_ADDR                            = 0X08,
      ACCEL_DATA_X_MSB_ADDR                            = 0X09,
      ACCEL_DATA_Y_LSB_ADDR                            = 0X0A,
      ACCEL_DATA_Y_MSB_ADDR                            = 0X0B,
      ACCEL_DATA_Z_LSB_ADDR                            = 0X0C,
      ACCEL_DATA_Z_MSB_ADDR                            = 0X0D,

      /* Mag data register */
      MAG_DATA_X_LSB_ADDR                              = 0X0E,
      MAG_DATA_X_MSB_ADDR                              = 0X0F,
      MAG_DATA_Y_LSB_ADDR                              = 0X10,
      MAG_DATA_Y_MSB_ADDR                              = 0X11,
      MAG_DATA_Z_LSB_ADDR                              = 0X12,
      MAG_DATA_Z_MSB_ADDR                              = 0X13,

      /* Gyro data registers */
      GYRO_DATA_X_LSB_ADDR                             = 0X14,
      GYRO_DATA_X_MSB_ADDR                             = 0X15,
      GYRO_DATA_Y_LSB_ADDR                             = 0X16,
      GYRO_DATA_Y_MSB_ADDR                             = 0X17,
      GYRO_DATA_Z_LSB_ADDR                             = 0X18,
      GYRO_DATA_Z_MSB_ADDR                             = 0X19,

      /* Euler data registers */
      EULER_H_LSB_ADDR                                 = 0X1A,
      EULER_H_MSB_ADDR                                 = 0X1B,
      EULER_R_LSB_ADDR                                 = 0X1C,
      EULER_R_MSB_ADDR                                 = 0X1D,
      EULER_P_LSB_ADDR                                 = 0X1E,
      EULER_P_MSB_ADDR                                 = 0X1F,

      /* Quaternion data registers */
      QUATERNION_DATA_W_LSB_ADDR                       = 0X20,
      QUATERNION_DATA_W_MSB_ADDR                       = 0X21,
      QUATERNION_DATA_X_LSB_ADDR                       = 0X22,
      QUATERNION_DATA_X_MSB_ADDR                       = 0X23,
      QUATERNION_DATA_Y_LSB_ADDR                       = 0X24,
      QUATERNION_DATA_Y_MSB_ADDR                       = 0X25,
      QUATERNION_DATA_Z_LSB_ADDR                       = 0X26,
      QUATERNION_DATA_Z_MSB_ADDR                       = 0X27,

      /* Linear acceleration data registers */
      LINEAR_ACCEL_DATA_X_LSB_ADDR                     = 0X28,
      LINEAR_ACCEL_DATA_X_MSB_ADDR                     = 0X29,
      LINEAR_ACCEL_DATA_Y_LSB_ADDR                     = 0X2A,
      LINEAR_ACCEL_DATA_Y_MSB_ADDR                     = 0X2B,
      LINEAR_ACCEL_DATA_Z_LSB_ADDR                     = 0X2C,
      LINEAR_ACCEL_DATA_Z_MSB_ADDR                     = 0X2D,

      /* Gravity data registers */
      GRAVITY_DATA_X_LSB_ADDR                          = 0X2E,
      GRAVITY_DATA_X_MSB_ADDR                          = 0X2F,
      GRAVITY_DATA_Y_LSB_ADDR                          = 0X30,
      GRAVITY_DATA_Y_MSB_ADDR                          = 0X31,
      GRAVITY_DATA_Z_LSB_ADDR                          = 0X32,
      GRAVITY_DATA_Z_MSB_ADDR                          = 0X33,

      /* Temperature data register */
      TEMP_ADDR                                        = 0X34,

      /* Status registers */
      CALIB_STAT_ADDR                                  = 0X35,
      SELFTEST_RESULT_ADDR                             = 0X36,
      INTR_STAT_ADDR                                   = 0X37,

      SYS_CLK_STAT_ADDR                                = 0X38,
      SYS_STAT_ADDR                                    = 0X39,
      SYS_ERR_ADDR                                     = 0X3A,

      /* Unit selection register */
      UNIT_SEL_ADDR                                    = 0X3B,
      DATA_SELECT_ADDR                                 = 0X3C,

      /* Mode registers */
      OPR_MODE_ADDR                                    = 0X3D,
      PWR_MODE_ADDR                                    = 0X3E,

      SYS_TRIGGER_ADDR                                 = 0X3F,
      TEMP_SOURCE_ADDR                                 = 0X40,

      /* Axis remap registers */
      AXIS_MAP_CONFIG_ADDR                             = 0X41,
      AXIS_MAP_SIGN_ADDR                               = 0X42,

      /* SIC registers */
      SIC_MATRIX_0_LSB_ADDR                            = 0X43,
      SIC_MATRIX_0_MSB_ADDR                            = 0X44,
      SIC_MATRIX_1_LSB_ADDR                            = 0X45,
      SIC_MATRIX_1_MSB_ADDR                            = 0X46,
      SIC_MATRIX_2_LSB_ADDR                            = 0X47,
      SIC_MATRIX_2_MSB_ADDR                            = 0X48,
      SIC_MATRIX_3_LSB_ADDR                            = 0X49,
      SIC_MATRIX_3_MSB_ADDR                            = 0X4A,
      SIC_MATRIX_4_LSB_ADDR                            = 0X4B,
      SIC_MATRIX_4_MSB_ADDR                            = 0X4C,
      SIC_MATRIX_5_LSB_ADDR                            = 0X4D,
      SIC_MATRIX_5_MSB_ADDR                            = 0X4E,
      SIC_MATRIX_6_LSB_ADDR                            = 0X4F,
      SIC_MATRIX_6_MSB_ADDR                            = 0X50,
      SIC_MATRIX_7_LSB_ADDR                            = 0X51,
      SIC_MATRIX_7_MSB_ADDR                            = 0X52,
      SIC_MATRIX_8_LSB_ADDR                            = 0X53,
      SIC_MATRIX_8_MSB_ADDR                            = 0X54,

      /* Accelerometer Offset registers */
      ACCEL_OFFSET_X_LSB_ADDR                          = 0X55,
      ACCEL_OFFSET_X_MSB_ADDR                          = 0X56,
      ACCEL_OFFSET_Y_LSB_ADDR                          = 0X57,
      ACCEL_OFFSET_Y_MSB_ADDR                          = 0X58,
      ACCEL_OFFSET_Z_LSB_ADDR                          = 0X59,
      ACCEL_OFFSET_Z_MSB_ADDR                          = 0X5A,

      /* Magnetometer Offset registers */
      MAG_OFFSET_X_LSB_ADDR                            = 0X5B,
      MAG_OFFSET_X_MSB_ADDR                            = 0X5C,
      MAG_OFFSET_Y_LSB_ADDR                            = 0X5D,
      MAG_OFFSET_Y_MSB_ADDR                            = 0X5E,
      MAG_OFFSET_Z_LSB_ADDR                            = 0X5F,
      MAG_OFFSET_Z_MSB_ADDR                            = 0X60,

      /* Gyroscope Offset register s*/
      GYRO_OFFSET_X_LSB_ADDR                           = 0X61,
      GYRO_OFFSET_X_MSB_ADDR                           = 0X62,
      GYRO_OFFSET_Y_LSB_ADDR                           = 0X63,
      GYRO_OFFSET_Y_MSB_ADDR                           = 0X64,
      GYRO_OFFSET_Z_LSB_ADDR                           = 0X65,
      GYRO_OFFSET_Z_MSB_ADDR                           = 0X66,

      /* Radius registers */
      ACCEL_RADIUS_LSB_ADDR                            = 0X67,
      ACCEL_RADIUS_MSB_ADDR                            = 0X68,
      MAG_RADIUS_LSB_ADDR                              = 0X69,
      MAG_RADIUS_MSB_ADDR                              = 0X6A
    };

    enum
    {
      PWMODE_NORMAL                                       = 0X00,
      PWMODE_LOWPOWER                                     = 0X01,
      PWMODE_SUSPEND                                      = 0X02
    };

    enum OPMODE {
      /* Operation mode settings*/
      OPMODE_CONFIG                                    = 0X00,
      OPMODE_ACCONLY                                   = 0X01,
      OPMODE_MAGONLY                                   = 0X02,
      OPMODE_GYRONLY                                   = 0X03,
      OPMODE_ACCMAG                                    = 0X04,
      OPMODE_ACCGYRO                                   = 0X05,
      OPMODE_MAGGYRO                                   = 0X06,
      OPMODE_AMG                                       = 0X07,
      OPMODE_IMUPLUS                                   = 0X08,
      OPMODE_COMPASS                                   = 0X09,
      OPMODE_M4G                                       = 0X0A,
      OPMODE_NDOF_FMC_OFF                              = 0X0B,
      OPMODE_NDOF                                      = 0X0C
    };

public:
    BNO055(uint8_t address = BNO055_ADDRESS_B);

    void Begin();

    void SetMode(OPMODE mode);
    OPMODE GetMode() const;

    void SetUnits(uint8_t unitsel);

    float GetTemperature() const;
    Vector3<float> GetEuleur() const;

private:
    uint8_t read8(uint8_t reg_addr) const;
    void readLen(uint8_t reg_addr, uint8_t* buf, size_t len) const;
    Vector3<float> readVec(uint8_t reg_addr) const;
    void write8(uint8_t reg_addr, uint8_t value);

private:
    uint8_t addr;
    OPMODE mode;
};

#endif // BNO055_HPP