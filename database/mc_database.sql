SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mc_database
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mc_database
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mc_database` DEFAULT CHARACTER SET utf8 ;
USE `mc_database` ;

-- -----------------------------------------------------
-- Table `mc_database`.`room`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mc_database`.`room` ;

CREATE TABLE IF NOT EXISTS `mc_database`.`room` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `temperature` VARCHAR(10) NOT NULL,
  `humidity` VARCHAR(10) NOT NULL,
  `air_conditioning` VARCHAR(10) NOT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;