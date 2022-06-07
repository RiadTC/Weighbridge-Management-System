-- MySQL Script generated by MySQL Workbench
-- Sat 14 May 2016 10:37:36 WAT
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema Weighbridge
-- -----------------------------------------------------
-- Database storing weighbridge data

-- -----------------------------------------------------
-- Schema Weighbridge
--
-- Database storing weighbridge data
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `Weighbridge` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `Weighbridge` ;

-- -----------------------------------------------------
-- Table `Weighbridge`.`Operator`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`Operator` (
  `OperatorID` INT NOT NULL COMMENT 'Users allowed to access the system',
  `Name` VARCHAR(45) BINARY NULL COMMENT '',
  `Password` VARCHAR(45) BINARY NULL COMMENT '',
  PRIMARY KEY (`OperatorID`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Weighbridge`.`Ticket`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`Ticket` (
  `TicketID` INT NOT NULL COMMENT '',
  `CustomerID` INT NULL COMMENT '',
  `OperatorID` INT NULL COMMENT '',
  `TimeIn` DATETIME NULL COMMENT '',
  `TimeOut` DATETIME NULL COMMENT '',
  `Empty` INT NULL COMMENT '',
  `Full` INT NULL COMMENT '',
  `DriverName` VARCHAR(15) NULL COMMENT '',
  `Transporter` VARCHAR(30) NULL COMMENT '',
  `Vehicule` VARCHAR(12) NULL COMMENT '',
  `MaterialID` INT NULL COMMENT '',
  PRIMARY KEY (`TicketID`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Weighbridge`.`Material`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`Material` (
  `MaterialID` INT NOT NULL COMMENT '',
  `ShortDesc` VARCHAR(10) NULL COMMENT '',
  `LongDesc` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`MaterialID`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Weighbridge`.`Customer`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`Customer` (
  `CustomerID` INT NOT NULL COMMENT '',
  `CustName` VARCHAR(45) NULL COMMENT '',
  `CustPhone1` VARCHAR(45) NULL COMMENT '',
  `CustPhone2` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`CustomerID`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Weighbridge`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`user` (
  `username` VARCHAR(16) NOT NULL COMMENT '',
  `email` VARCHAR(255) NULL COMMENT '',
  `password` VARCHAR(32) NOT NULL COMMENT '',
  `create_time` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP COMMENT '');


-- -----------------------------------------------------
-- Table `Weighbridge`.`Log`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`Log` (
  `EntryID` TIMESTAMP(1) NOT NULL COMMENT '',
  `Time` DATETIME NULL COMMENT '',
  `Action` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`EntryID`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Weighbridge`.`Serial`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Weighbridge`.`Serial` (
  `idSerial` INT NULL COMMENT '',
  PRIMARY KEY (`idSerial`)  COMMENT '')
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
